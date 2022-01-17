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

		ID3D11RenderTargetView* RenderTargetView;
	}

	void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
			case WM_CREATE:
			{
				DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();
				Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
				// DXGI_FORMAT_B8G8R8A8_UNORM explain

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