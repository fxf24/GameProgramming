#include <d3d11.h>
#include <assert.h>

#include "Pipeline.h"

namespace Rendering::Pipeline
{
	void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
		case WM_CREATE:
		{
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