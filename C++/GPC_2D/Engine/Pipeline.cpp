#include "Pipeline.h"
#include <iostream>
#include <d3d11.h>
#include <cassert>

#pragma warning(suppress : 4819)
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
		ID3D11Device*           Device;
		ID3D11DeviceContext*    DeviceContext;

		IDXGISwapChain*         SwapChain;
		
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
			{
				DXGI_SWAP_CHAIN_DESC Desciptor = DXGI_SWAP_CHAIN_DESC();

				Desciptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
				Desciptor.SampleDesc.Count = 1;
				Desciptor.SampleDesc.Quality = 0;
				Desciptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
				Desciptor.BufferCount = 1;
				Desciptor.OutputWindow = hWindow;
				Desciptor.Windowed = true;

				MUST(D3D11CreateDeviceAndSwapChain
				(
					nullptr,
					D3D_DRIVER_TYPE_HARDWARE,
					nullptr,
					10,
					nullptr,
					0,
					D3D11_SDK_VERSION,
					&Desciptor,
					&SwapChain,
					&Device,
					nullptr,
					&DeviceContext
				));
			}
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
				
				Descriptor.MiscFlags = 0; 
				Descriptor.StructureByteStride = 0; 

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
				DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
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