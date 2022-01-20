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

		IDXGISwapChain*			SwapChain;

		namespace Buffer
		{
			ID3D11Buffer* Vertex;
			ID3D11Buffer* Constant[2];

			template<typename Data>
			void Update(ID3D11Buffer const* buffer, Data const& data)
			{
				D3D11_MAPPED_SUBRESOURCE Subresource = D3D11_MAPPED_SUBRESOURCE();

				MUST(DeviceContext->Map(buffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &Subresource));
				{
					memcpy_s(Subresource.pData, Subresource.RowPitch, data, sizeof(data));
				}
				DeviceContext->Unmap(buffer, 0);
			}
		}

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
#include "Shader/Bytecode/Vertex.h"
					{
						D3D11_INPUT_ELEMENT_DESC const Descriptor[2]
						{
							{"POSITION",0, DXGI_FORMAT_R32G32_FLOAT, 0},
							{"TEXCOORD",0, DXGI_FORMAT_R32G32_FLOAT, 1}
						};
						
						ID3D11InputLayout* InputLayout = nullptr;

						MUST(Device->CreateInputLayout(Descriptor, 2, Bytecode, sizeof(Bytecode), &InputLayout));
						
						DeviceContext->IASetInputLayout(InputLayout);

						InputLayout->Release();
					}
					{
						ID3D11VertexShader* VertexShader = nullptr;
						
						MUST(Device->CreateVertexShader(Bytecode, sizeof(Bytecode), nullptr, &VertexShader));

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
					D3D11_BUFFER_DESC Descriptor
					{
						sizeof(float[4][4]),
						D3D11_USAGE_DYNAMIC,
						D3D11_BIND_CONSTANT_BUFFER,
						D3D11_CPU_ACCESS_WRITE
					};

					for (int i = 0; i < 2; i++) {
						MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Constant[i]));
					}

					DeviceContext->VSSetConstantBuffers(0, 2, Buffer::Constant);
				}
				return;
			}
			case WM_APP:
			{
				return;
			}
			case WM_DESTROY:
			{
				for (int i = 0; i < 2; i++) {
					Buffer::Constant[i]->Release();
				}
				Buffer::Vertex->Release();
				SwapChain->Release();
				DeviceContext->Release();
				Device->Release();
				return;
			}
			case WM_SIZE:
			{
				return;
			}
		}
	}
}