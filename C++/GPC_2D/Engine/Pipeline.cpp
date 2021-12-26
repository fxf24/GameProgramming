#include "Pipeline.h"
#include <iostream>
#include <d3d11.h> // connect to d3d11.lib to use it
#include <cassert>

// DirectX
// API that can do graphic computing procedure through GPU
// GPU is Graphic Card etc.
// CPU is vertical computing that sequently proceed, so useful to handle 
// complex computing.
// GPU is horizontal computing so that easy to handle simple computing.
// Rendering Pipeline
// Procedure that computer draw image for us.
// IA (Input Assemble) -> VS(Vertex Shader) -> RS(Rasterizer) 
// -> PS(Pixel Shader) -> OM(Output Merge)
// IA : set vertices, set topology
// VS : compute vertices' information, set vertices' location, set camera's location
// RS : compute 3D to 2D (viewport), backspace culling, clipping, make vertices to pixel 
// PS : extract color of pixel 
// OM : merge all the stage and send it to rendertarget

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#if not defined _DEBUG
#define MUST(Expression) (      (         (Expression)))
#else
#define MUST(Expression) (assert(SUCCEEDED(Expression)))
#endif

namespace Pipeline
{
	namespace
	{
		// Device : making resources that GPU will use
		ID3D11Device*           Device;
		// DeviceContext : connect resources that device made to rendering pipeline
		ID3D11DeviceContext*    DeviceContext;
		// Buffer : have data that will be printed on screen
		// SwapChain : make multiple buffers and set buffers what to do
		IDXGISwapChain*         SwapChain;
		// I : ComInterface : computer makes data automatically
		// release() function to release data
		// make descriptor to set what to do

		ID3D11InputLayout*		InputLayout; 
		ID3D11VertexShader*		VertexShader;	// vertexshader
		ID3D11PixelShader*		PixelShader;	// pixelshader

		namespace Buffer
		{
			ID3D11Buffer* Vertex; 
		}

		ID3D11RenderTargetView* RenderTargetView;
	}

	void CALLBACK Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
		case WM_CREATE:
		{
//#include "Shader/Bytecode/Vertex.h"

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

				MUST(D3D11CreateDeviceAndSwapChain
				(
					nullptr,
					D3D_DRIVER_TYPE_HARDWARE,
					nullptr,
					0,
					nullptr,
					0,
					D3D11_SDK_VERSION,
					&Descriptor,
					&SwapChain,
					&Device,
					nullptr,
					&DeviceContext
				));
			}
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

				//// VS uses 
				//// numelements : 
				//// ppInputLayout : pointer address
				//// IA(Input Assembler) -> VS(Vertex Shader) -> RS(Rasterizer) -> PS(Pixel Shader) -> OM(OutputMarge)
				//// Device : Object that make resources where redering pipline
				//// DeviceContext : connecting resources that device made and rendering pipeline
				//// SV(System Value) 
				//MUST(Device->CreateInputLayout(Descriptor, 2, Bytecode, sizeof(Bytecode), &InputLayout));

				//DeviceContext->IASetInputLayout(InputLayout);
			}
			{
				/*MUST(Device->CreateVertexShader(Bytecode, sizeof(Bytecode), nullptr, &VertexShader));
				DeviceContext->VSSetShader(VertexShader, nullptr, 0);*/
			}
		}
		{
/*#include "Shader/Bytecode/Pixel.h"
			MUST(Device->CreatePixelShader(Bytecode, sizeof(Bytecode), nullptr, &PixelShader));
			DeviceContext->PSSetShader(PixelShader, nullptr, 0);*/
		}
		{
			{
				struct Vertex final
				{
					float Position[4];
					float	 Color[4];
				};

				Vertex const Vertices[4]
				{
					{ { -0.5f, +0.5f, 0.0f, 1.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
					{ { +0.5f, +0.5f, 0.0f, 1.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
					{ { -0.5f, -0.5f, 0.0f, 1.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } },
					{ { +0.5f, -0.5f, 0.0f, 1.0f }, { 1.0f, 1.0f, 1.0f, 1.0f } }
				};

				D3D11_BUFFER_DESC Descriptor = D3D11_BUFFER_DESC();
				
				Descriptor.ByteWidth = sizeof(Vertices);
				Descriptor.Usage	 = D3D11_USAGE_IMMUTABLE; 
				Descriptor.BindFlags = D3D11_BIND_VERTEX_BUFFER; 
				Descriptor.CPUAccessFlags = 0; 
				Descriptor.MiscFlags = 0;	// extra func
				Descriptor.StructureByteStride = 0; // divide buffer with what size

				D3D11_SUBRESOURCE_DATA Subresource = D3D11_SUBRESOURCE_DATA();
				Subresource.pSysMem = Vertices;

				MUST(Device->CreateBuffer(&Descriptor, &Subresource, &Buffer::Vertex));
				//MUST(Device->CreateBuffer(&Descriptor, &Subresource, &Buffer::Vertex));
				//ID3D11Buffer* array[2] = { Buffer::Vertex, Buffer::Vertex };
				
				UINT const Stride = sizeof(Vertex);
				UINT const Offset = 0;
				
				DeviceContext->IASetVertexBuffers(0, 1, &Buffer::Vertex, &Stride, &Offset);
				
			}
			{
				// vertex info
				DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP); 
			}
			return;
		}
		case WM_APP:
		{
			MUST(SwapChain->Present(0, 0));

			static float a = 0;

			static float delta = 0.0001f;

			a += delta;

			float Color[4] = { a, 1.0f, 1.0f, 1.0f };

			if (a >= 1.0f || a <= 0.0f) delta *= -1.0f;

			DeviceContext->ClearRenderTargetView(RenderTargetView, Color);
			// 2
			// DeviceContext->Draw(4, 0); // Indexcount, startindex, startvertex
			// CPU : vertical compute
			// GPU : horizontal compute // gpu draw image for us
			return;
		}
		case WM_DESTROY:
		{
			SwapChain->Release();
			DeviceContext->Release();
			Device->Release();
			return;
		}
		case WM_SIZE:
		{
			{
				D3D11_VIEWPORT Viewport = D3D11_VIEWPORT();
				Viewport.Width  = LOWORD(lParameter);
				Viewport.Height = HIWORD(lParameter);

				DeviceContext->RSSetViewports(1, &Viewport);
			}
			{
				if (RenderTargetView != nullptr)
				{
					RenderTargetView->Release();

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
				ID3D11Texture2D* Texture2D = nullptr;
				
				MUST(SwapChain->GetBuffer(0, IID_PPV_ARGS(&Texture2D)));
				{
					MUST(Device->CreateRenderTargetView(Texture2D, nullptr, &RenderTargetView));
				}
				Texture2D->Release();

				DeviceContext->OMSetRenderTargets(1, &RenderTargetView, nullptr);
			}
			return;
		}
		}
	}
}