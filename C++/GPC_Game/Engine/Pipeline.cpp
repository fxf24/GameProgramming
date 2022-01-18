#include <d3d11.h>
#include <assert.h>

#include "Pipeline.h"

#if not defined _DEBUG
#define MUST(Expression) (		(		  (Expression)))
#else 
#define MUST(Expression) (assert(SUCCEEDED(Expression)))
#endif

namespace Rendering::Pipeline
{
	namespace
	{
		ID3D11Device*			Device;
		ID3D11DeviceContext*	DeviceContext;

		namespace Buffer
		{
			ID3D11Buffer* Vertex;
			ID3D11Buffer* Constant[3];
		}

		IDXGISwapChain*			SwapChain;
		ID3D11InputLayout*		InputLayout;
		ID3D11RenderTargetView* RenderTargetView;
	}

	void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
			case WM_CREATE:
			{
				{
					DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();
					Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
					// DXGI_FORMAT_B8G8R8A8_UNORM explain
					// unorm = information transportation of lightweight
					Descriptor.SampleDesc.Count = 1;
					Descriptor.BufferCount = 1;
					Descriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
					Descriptor.OutputWindow = hWindow;
					Descriptor.Windowed = true;

					MUST(D3D11CreateDeviceAndSwapChain(
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
					{
						ID3D11VertexShader* VertexShader = nullptr;
						
						//MUST(Device->CreateVertexShader(, , , ));
						DeviceContext->VSSetShader(VertexShader, nullptr, 0);
						VertexShader->Release();
					}
				}
				{
					float const Coordinate[4][2]
					{
						{-0.5f, 0.5f},
						{0.5f, 0.5f},
						{-0.5f, -0.5f},
						{0.5f, -0.5f}
					};
					
					D3D11_BUFFER_DESC const Descriptor
					{
						sizeof(Coordinate),
						D3D11_USAGE_IMMUTABLE,
						D3D11_BIND_VERTEX_BUFFER,
						0
					};

					D3D11_SUBRESOURCE_DATA Subresource{ Coordinate };

					ID3D11Buffer* Buffer = nullptr;

					MUST(Device->CreateBuffer(&Descriptor, &Subresource, &Buffer));

					const UINT stride = sizeof(float[2]);
					const UINT offset = 0;

					DeviceContext->IASetVertexBuffers(0, 1, &Buffer, &stride, &offset);

					Buffer->Release();
				}
				{
					D3D11_BUFFER_DESC const Descriptor
					{
						sizeof(float[4][2]),
						D3D11_USAGE_DYNAMIC,
						D3D11_BIND_VERTEX_BUFFER,
						D3D11_CPU_ACCESS_WRITE
					};

					MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Vertex));

					const UINT stride = sizeof(float[2]);
					const UINT offset = 0;

					DeviceContext->IASetVertexBuffers(1, 1, &Buffer::Vertex, &stride, &offset);
				}
				{
					DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
				}
				{
					
				}
				return;
			}
			case WM_APP:
			{
				return;
			}
			case WM_DESTROY:
			{
				return;
			}
			case WM_SIZE:
			{
				return;
			}
		}
	}
}