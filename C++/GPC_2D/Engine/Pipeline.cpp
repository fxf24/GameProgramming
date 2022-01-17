#include "Pipeline.h"
#include <iostream>
#include <d3d11.h> // connect to d3d11.lib to use it // contain windows.h
#include <cassert> // to use assert() function
#include "matrix.h"
#include "FreeImage.h"
// DirectX
// API that can do graphic computing procedure through GPU
// GPU is Graphic Card etc.
// CPU is vertical computing that sequently proceed, so useful to handle 
// complex computing.
// GPU is horizontal computing so that easy to handle simple computing.
// Rendering Pipeline
// Procedure that computer draw image for us.
// IA -> VS -> (HS -> TS -> DS -> GS -> SO) -> RS -> PS -> OM
// cannot set hs~so step
// IA (Input Assemble) -> VS(Vertex Shader) -> RS(Rasterizer) 
// -> PS(Pixel Shader) -> OM(Output Merge)
// Shader : functions that gpu can use, hlsl 
// IA : set vertices, set topology
// VS : compute vertices' information, set vertices' location, set camera's location
// RS : compute 3D to 2D (viewport), backspace culling, clipping, make vertices to pixel 
// PS : extract color of pixel 
// OM : merge all the stage and send it to rendertarget

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console") // show console

#if not defined _DEBUG
#define MUST(Expression) (      (         (Expression)))
#else
#define MUST(Expression) (assert(SUCCEEDED(Expression))) // assert break program
#endif

// HRESULT Contains error information
// SEVERITY_ERROR;
// SEVERITY_SUCCESS;

namespace Input
{
	bool CALLBACK isPressed(WPARAM const code);
}
using namespace Input;

namespace Pipeline
{
	namespace
	{
		// Device : making resources that GPU will use
		ID3D11Device*           Device;
		// DeviceContext : connect resources that device made to rendering pipeline
		ID3D11DeviceContext*    DeviceContext;
		// Buffer : have data that will be printed on screen
		// SwapChain : make multiple buffers and set buffers what to do, takes turn to use buffers
		// DXGI : be compatible to version of direct x
		IDXGISwapChain*         SwapChain;
		// I : ComInterface : computer makes data automatically, dynamic allocation
		// release() function to release data
		// make descriptor to set what to do

		// inputlayout is kind of filter
		ID3D11InputLayout*		InputLayout; 
		// vs, ps = pipe
		ID3D11VertexShader*		VertexShader;	// vertexshader
		ID3D11PixelShader*		PixelShader;	// pixelshader

		namespace Buffer
		{
			// data resource
			ID3D11Buffer* Vertex; 
			ID3D11Buffer* Constant[3];

			template<typename Data>
			void Update(ID3D11Buffer* const buffer, Data const& data)
			{
				D3D11_MAPPED_SUBRESOURCE Subresource = D3D11_MAPPED_SUBRESOURCE();

				MUST(DeviceContext->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &Subresource));
				{
					memcpy_s(Subresource.pData, Subresource.RowPitch, data, sizeof(data));
				}
				DeviceContext->Unmap(buffer, 0);
			}
		}

		// draw resouce on the screen
		ID3D11RenderTargetView* RenderTargetView;
	}

	void CALLBACK Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
		case WM_CREATE:
		{
			{
				// descriptor for swapchain 
				DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC( );

				// LOWORD(lParameter) 
				// HIWORD(lParameter)
				// computer automatically make buffer fit to screen size 
				// if you set width and height 0.
				// Descriptor.BufferDesc.Width = 0; Set buffersize as screen size
				// Descriptor.BufferDesc.Height = 0;
				
				// 0 / 0 = error -> 0 / 1
				// set 0 0 means auto frame
				// Descriptor.BufferDesc.RefreshRate.Denominator = 0; // 60
				// Descriptor.BufferDesc.RefreshRate.Numerator = 0; // 1
				
				// DXGI_FORMAT_B8G8R8A8_UNORM
				// red   (0, 255) = 0~255 >> unsigned char == 1byte = 8 bit
				// blue  (0, 255)
				// green (0, 255)
				// A	 (0~255) 8 bit = 1byte  transparency
				// 32bit == 4byte == int, float
				// UNORM : normalize as 1
				// format : what data will you read
				// R G B A (0 0 1 1)
				// 0 0 1
				// B G R A (1 0 0 1)
				// 0 0 1
				// 1 0 0 1 << color we want
				// 4 3 2 1 << data sequence
				//
				Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
				
				// DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED = 0,		// dont set, computer automatic
				// DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE = 1,		// scan all the images and pop all at once
				// DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST = 2,	// scan from the top
				// DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST = 3	// scan from the bottom
				// Descriptor.BufferDesc.ScanlineOrdering;			// scan type
				
				// DXGI_MODE_SCALING_UNSPECIFIED = 0,	// dont set, computer automatic
				// DXGI_MODE_SCALING_CENTERED = 1,		// set screen from center, not using magnifying
				// DXGI_MODE_SCALING_STRETCHED = 2		// magnifying screen
				// Descriptor.BufferDesc.Scaling;		// screen view 
				
				// Anti-Aliasing
				// - super sampling : high cost, many pixels, slow
				// - multi sampling : low cost, only border
				// Count : divide one pixel with this number, multiple of 4
				Descriptor.SampleDesc.Count = 1; // 1 : not gonna divide 
				// Quality : high quality low speed, low quailty high speed
				Descriptor.SampleDesc.Quality = 0;
				
				// Buffer's usage 
				// DXGI_USAGE_RENDER_TARGET_OUTPUT : for drawing render target
				Descriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				// BufferCount : how many buffers do you use
				// 1 of the buffer is automatically created
				Descriptor.BufferCount = 1; // 1 = 2, 2 = 3;

				// OutputWindow : screen to show output
				Descriptor.OutputWindow = hWindow;
				// Windowed : window mode able/ disable
				Descriptor.Windowed = true;

				// SawpEffect  
				// DXGI_SWAP_EFFECT_DISCARD = 0,		// delete data
				// DXGI_SWAP_EFFECT_SEQUENTIAL = 1,		// buffer keep data
				// DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL = 3,// buffer take turns to do work
				// Descriptor.SwapEffect = 0;
				
				// Flags
				// extra function
				// Descriptor.Flags;

				/*D3D_FEATURE_LEVEL levels[6]
				{
					D3D_FEATURE_LEVEL_11_0,
					D3D_FEATURE_LEVEL_10_1,
					D3D_FEATURE_LEVEL_10_0,
					D3D_FEATURE_LEVEL_9_3,
					D3D_FEATURE_LEVEL_9_2,
					D3D_FEATURE_LEVEL_9_1
				};*/


				// HRESULT
				// SERVERITY_ERROR
				// SERVERITY_SUCCESS
				// HRESULT have error information
				// if function return HRESULT, use MUST() to assert program
				MUST(D3D11CreateDeviceAndSwapChain
				(
					nullptr,						// when connecting multi gpu
					D3D_DRIVER_TYPE_HARDWARE,		// directx driver location, where and how you make the driver
					// D3D_DRIVER_TYPE_UNKNOWN = 0,									don't know
					// D3D_DRIVER_TYPE_HARDWARE = (D3D_DRIVER_TYPE_UNKNOWN + 1),	use computer driver, hardware, best performance
					// D3D_DRIVER_TYPE_REFERENCE = (D3D_DRIVER_TYPE_HARDWARE + 1),	use dx driver (software) 
					// D3D_DRIVER_TYPE_NULL = (D3D_DRIVER_TYPE_REFERENCE + 1),		
					// use driver only for debugging, not using rendering driver
					// D3D_DRIVER_TYPE_SOFTWARE = (D3D_DRIVER_TYPE_NULL + 1),		use other software driver, not accurate 
					// D3D_DRIVER_TYPE_WARP = (D3D_DRIVER_TYPE_SOFTWARE + 1)		use warp driver (max : 10.1), software
					nullptr,						// HMODULE where you gonna get drivers
					0,								// Addtional functions
					nullptr,						// direct X version list, nullptr : 9.1~11.0
					0,								// how many versions will you use if array address is exist
					D3D11_SDK_VERSION,				// use D3D11_SDK_VERSION
					&Descriptor,					// DXGI_SWAP_CHAIN_DESC address
					&SwapChain,						// swapchain pointer address
					&Device,						// device pointer address
					nullptr,						// direct x version list
					&DeviceContext					// devicecontext pointer addresss
				));
			}
#include "Shader/Bytecode/Vertex.h"
			{
				//D3D11_INPUT_ELEMENT_DESC Descriptor[2]
				//{
				//	D3D11_INPUT_ELEMENT_DESC(),
				//	D3D11_INPUT_ELEMENT_DESC()
				//}; // what vertex input gonna do

				//Descriptor[0].SemanticName = "POSITION"; // first position's semanticname = POSITION
				//Descriptor[0].SemanticIndex = 0;
				//Descriptor[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT; // how do you divide the format
				//// DXGI_FORMAT_R32G32B32A32_FLOAT : read 16 byte 
				//// mostly format uses DXGI_FORMAT tags
				//Descriptor[0].InputSlot = 0; // what slot do you use
				//Descriptor[0].AlignedByteOffset = 0; // starting point;
				//Descriptor[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA; // what input data do you use
				//Descriptor[0].InstanceDataStepRate = 0; // if inputslotclass is vertex data, 0

				//// position : 0~15byte, color : 16~31byte
				//Descriptor[1].SemanticName = "COLOR"; // first position's semanticname = POSITION
				//Descriptor[1].SemanticIndex = 0;
				//Descriptor[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT; // how do you divide the format
				//Descriptor[1].InputSlot = 0; // what slot do you use
				//Descriptor[1].AlignedByteOffset = 16; // starting point;
				//Descriptor[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA; // what input data do you use
				//Descriptor[1].InstanceDataStepRate = 0; // if inputslotclass is vertex data, 0

				D3D11_INPUT_ELEMENT_DESC Descriptor[2]
				{
					{"POSITION", 0, DXGI_FORMAT_R32G32_FLOAT, 0},
					{"TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 1}
				};
				// VS uses 
				// numelements : 
				// ppInputLayout : pointer address
				// IA(Input Assembler) -> VS(Vertex Shader) -> RS(Rasterizer) -> PS(Pixel Shader) -> OM(OutputMarge)
				// Device : Object that make resources where redering pipline
				// DeviceContext : connecting resources that device made and rendering pipeline
				// SV(System Value) 

				// shader : function set that can do gpu calculation
				MUST(Device->CreateInputLayout(Descriptor, 2, Bytecode, sizeof(Bytecode), &InputLayout));

				DeviceContext->IASetInputLayout(InputLayout);
			}
			{
				MUST(Device->CreateVertexShader(Bytecode, sizeof(Bytecode), nullptr, &VertexShader));
				DeviceContext->VSSetShader(VertexShader, nullptr, 0);
			}
			{
#include "Shader/Bytecode/Pixel.h"
				MUST(Device->CreatePixelShader(Bytecode, sizeof(Bytecode), nullptr, &PixelShader));
				DeviceContext->PSSetShader(PixelShader, nullptr, 0);
			}
			{
				// vertex info
				DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP); 
			}
			{
				// CPU data
				float const Coordinates[4][2]
				{
					{ -0.5f, +0.5f},
					{ +0.5f, +0.5f},
					{ -0.5f, -0.5f},
					{ +0.5f, -0.5f}
				};
				// GPU resource for number data is buffer

				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(Coordinates),
					D3D11_USAGE_IMMUTABLE,
					D3D11_BIND_VERTEX_BUFFER,
					0
				};
				
				// initialize subresource with vertices data
				D3D11_SUBRESOURCE_DATA const Subresource{ Coordinates };

				ID3D11Buffer* Buffer = nullptr;

				// create buffer with descriptor, subresource, vertex
				MUST(Device->CreateBuffer(&Descriptor, &Subresource, &Buffer));

				UINT const Stride = sizeof(*Coordinates);
				UINT const Offset = 0;

				DeviceContext->IASetVertexBuffers(0, 1, &Buffer, &Stride, &Offset);
				Buffer->Release();
			}
			{
				// Buffer for animation
				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(float[4][2]),
					D3D11_USAGE_DYNAMIC,
					D3D11_BIND_VERTEX_BUFFER,
					D3D11_CPU_ACCESS_WRITE
				};

				// create buffer with descriptor, vertex
				MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Vertex));

				UINT const Stride = sizeof(float[2]);
				UINT const Offset = 0;

				DeviceContext->IASetVertexBuffers(1, 1, &Buffer::Vertex, &Stride, &Offset);
			}
			{
				D3D11_BUFFER_DESC const Descriptor
				{
					sizeof(float[4][4]),
					D3D11_USAGE_DYNAMIC,
					D3D11_BIND_CONSTANT_BUFFER,
					D3D11_CPU_ACCESS_WRITE
				};

				for (int i = 0; i < 3; i++) {
					MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Constant[i]));
				}
				
				DeviceContext->VSSetConstantBuffers(0, 3, Buffer::Constant);
			}
			{
				char const* const File = "Player.png";

				FreeImage_Initialise();
				{
					// Image load
					// FIBITMAP : to contain image file
					FIBITMAP* Bitmap = FreeImage_Load(FreeImage_GetFileType(File), File);
					{
						// flip the image 
						FreeImage_FlipVertical(Bitmap);

						D3D11_TEXTURE2D_DESC Descriptor = D3D11_TEXTURE2D_DESC();
						// Width;
						// Height;
						// MipLevels;		// divede size by 2^(level-1)
						// ArraySize;		// textures' count
						// Format;			// we only neee color so use DXGI_FORMAT_B8G8R8A8_UNORM
						// SampleDesc;		// 1, 0
						// Usage;			// immutable
						// BindFlags;		// resource's type
						// CPUAccessFlags;	// 0 
						// MiscFlags;		// etc 
						Descriptor.Width				= FreeImage_GetWidth(Bitmap);
						Descriptor.Height				= FreeImage_GetHeight(Bitmap);
						Descriptor.MipLevels			= 1;
						Descriptor.ArraySize			= 1;
						Descriptor.Format				= DXGI_FORMAT_B8G8R8A8_UNORM;
						Descriptor.SampleDesc.Count		= 1;
						Descriptor.SampleDesc.Quality	= 0;
						Descriptor.Usage				= D3D11_USAGE_IMMUTABLE;
						Descriptor.BindFlags			= D3D11_BIND_SHADER_RESOURCE;
						Descriptor.CPUAccessFlags		= 0;
						Descriptor.MiscFlags			= 0;

						D3D11_SUBRESOURCE_DATA Subresource = D3D11_SUBRESOURCE_DATA();
						Subresource.pSysMem = FreeImage_GetBits(Bitmap);
						Subresource.SysMemPitch = FreeImage_GetPitch(Bitmap); // size, length

						ID3D11Texture2D* Texture2D = nullptr;

						MUST(Device->CreateTexture2D(&Descriptor, &Subresource, &Texture2D));
						{
							// Read image data
							ID3D11ShaderResourceView* ShaderREsourceView = nullptr;
							MUST(Device->CreateShaderResourceView(Texture2D, nullptr, &ShaderREsourceView));
							{
								DeviceContext->PSSetShaderResources(0, 1, &ShaderREsourceView);
							}
							ShaderREsourceView->Release();
						}
						Texture2D->Release();
					}
					FreeImage_Unload(Bitmap);
				}
				FreeImage_DeInitialise();
			}
			return;
		}
		case WM_APP:
		{
			static bool flip = true;
			{
				D3D11_MAPPED_SUBRESOURCE Subresource = D3D11_MAPPED_SUBRESOURCE();
				
				// Buffer::Vertex
				// order a pipeline to get cpu data to gpu
				MUST(DeviceContext->Map(Buffer::Vertex, 0,
					D3D11_MAP_WRITE_DISCARD, // delete data when it is written
					0, &Subresource));
				{
					static struct
					{
						float const Width  = 84;
						float const Height = 120;
					}Frame;

					static unsigned Count  = 0;
					static unsigned Motion = 12;
					static unsigned FPM	   = 256;


					float const Coordinates[4][2]
					{
						{ Frame.Width * (Count / FPM),		0},
						{ Frame.Width * (Count / FPM + 1),	0},
						{ Frame.Width * (Count / FPM),		Frame.Height},
						{ Frame.Width * (Count / FPM + 1),	Frame.Height},
					};

					float const LeftCoordinates[4][2]
					{
						{ Frame.Width * (Count / FPM + 1),		0},
						{ Frame.Width * (Count / FPM ),	0},
						{ Frame.Width * (Count / FPM + 1),		Frame.Height},
						{ Frame.Width * (Count / FPM ),	Frame.Height},
					};
					Count += 1;

					if (FPM * Motion - 1 < Count)
						Count = 0;
					// pData : what data
					// RowPitch : How big is the data
					if (flip) {
						memcpy_s(Subresource.pData, Subresource.RowPitch, Coordinates, sizeof(Coordinates));	
					}
					else {
						memcpy_s(Subresource.pData, Subresource.RowPitch, LeftCoordinates, sizeof(LeftCoordinates));
					}
				}
				DeviceContext->Unmap(Buffer::Vertex, 0);
			}
			{
				float const W = 84;
				float const H = 120;

				static float X = 0.0f;
				static float Y = 0.0f;
				static float size = 1.0f;

				
				if (isPressed('W')  && Y < 250 - (H * size / 2)) {
					Y += 0.1f;
				}
				if (isPressed('S') && Y > -250 + (H * size / 2)) {
					Y -= 0.1f;
				}
				if (isPressed('A') && X > -250 + (W * size / 2)) {
					X -= 0.1f;
					flip = false;
				}
				if (isPressed('D')  && X < 250 - (W * size / 2)) {
					X += 0.1f;
					flip = true;
				}
				if (isPressed(VK_UP) && size <= 2)
				{
					size += 0.001f;
				}
				if (isPressed(VK_DOWN) && size >= 0.1)
				{
					size -= 0.001f;
				}

				float const Transform[4][4]
				{
					W * size, 0, 0, X,
					0, H * size, 0, Y,
					0, 0, 1, 0,
					0, 0, 0, 1
				};

				// 1. wasd to move player
				// 2. Up, down key to size up, down

				Buffer::Update(Buffer::Constant[0], Transform);
		
				float const Camera[4][4]
				{
					1, 0, 0, -X,
					0, 1, 0, -Y,
					0, 0, 1, 0,
					0, 0, 0, 1
				};

				Buffer::Update(Buffer::Constant[1], Camera);
			
				// when rectangle size is 1
				// 1 = 250
				float const XS = 2.0f / 500.0f;
				float const YS = 2.0f / 500.0f;

				float const Projection[4][4]
				{
					XS, 0, 0, 0,
					0, YS, 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
				};

				Buffer::Update(Buffer::Constant[2], Projection);
			}
			{
				float Color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

				// draw canvas to this color
				DeviceContext->ClearRenderTargetView(RenderTargetView, Color);
				
				// VertexCount : how many vertices
				// StartVertexLocation : where to start
				DeviceContext->Draw(4, 0); 
				// CPU : vertical compute
				// GPU : horizontal compute // gpu draw image for us
				
				// backbuffer to screen buffer
				// screen buffer to screen
				MUST(SwapChain->Present(0, 0));
			}
			return;
		}
		case WM_DESTROY:
		{
			// Cominterface use release to delete
			// LIFO recommended
			SwapChain->Release();
			DeviceContext->Release();
			Device->Release();
			return;
		}
		
		case WM_SIZE:
		{
			{
				// area will draw rendertarget
				// 3d to 2d
				D3D11_VIEWPORT Viewport = D3D11_VIEWPORT();
				Viewport.Width  = LOWORD(lParameter);
				Viewport.Height = HIWORD(lParameter);

				DeviceContext->RSSetViewports(1, &Viewport);
			}
			{
				if (RenderTargetView != nullptr)
				{
					RenderTargetView->Release();

					// resize buffer size
					MUST(SwapChain->ResizeBuffers
					(
						1,
						LOWORD(lParameter),
						HIWORD(lParameter),
						DXGI_FORMAT_B8G8R8A8_UNORM,
						0
					));
				}
			}
			{
				// ID3D11Resource that GPU will use
				ID3D11Texture2D* Texture2D = nullptr;
				
				// IID_PPV_ARGS
				// get resources from buffer that number is same as MIDL_Interface number and put it in to Texture2D
				// from buffer to texture2D
				MUST(SwapChain->GetBuffer(0, IID_PPV_ARGS(&Texture2D)));
				{
					// resource create
					// set Texture2D's resource to draw
					// save texture2D to rendertargetview
					// make rendertargetview to draw Texture2D
					MUST(Device->CreateRenderTargetView(Texture2D, nullptr, &RenderTargetView));
				}
				Texture2D->Release();

				// merge with rendering pipeline
				// NumViews : how many view you use
				// ID3D11RenderTargetView address
				// ID3D11DepthStencilView : depth resource address
				DeviceContext->OMSetRenderTargets(1, &RenderTargetView, nullptr);
			}
			return;
		}
		}
	}
}

// ()				: usually don't use, too strong
// static_cast		: good cast
// dynamic_cast		: Use it when it is in extends relationship
// const_cast		: temporarily remove const 
// reinterpret_cast	: pointer casting, usually don't use
//