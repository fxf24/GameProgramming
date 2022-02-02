#include <Windows.h>

#define _USE_MATH_DEFINES

#include <map>
#include <string>

#include "FreeImage.h"
#include "Pipeline.h"
#include "Rendering.h"

namespace Rendering
{
	namespace
	{
		inline matrix<4, 4> Scale(vector<2> length)
		{
			return matrix<4, 4>
			{
				length[0],	0,			0, 0,
					0,		length[1],	0, 0,
					0,		0,			1, 0,
					0,		0,			0, 1
			};
		}

		inline matrix<4, 4> Rotation(float angle)
		{
			float const radian = static_cast<float>(M_PI) / 180.0f * angle;

			return matrix<4, 4>
			{
					cos(radian), -sin(radian), 0, 0,
					sin(radian),  cos(radian), 0, 0,
					0, 0, 1, 0,
					0, 0, 0, 1
			};
		}

		inline matrix<4, 4> Translation(vector<2> location)
		{
			return matrix<4, 4>
			{
					1, 0, 0, location[0],
					0, 1, 0, location[1],
					0, 0, 1, 0,
					0, 0, 0, 1
			};
		}
	}

	namespace Image
	{
		struct Descriptor final
		{
		public :
			Pipeline::Texture::Handle* handle = nullptr;

		public :
			SIZE size = SIZE();
		};

		std::map<std::string, Descriptor> Storage;

		void Import(std::string const& file)
		{
			{
				
				FIBITMAP* bitmap = FreeImage_Load(FreeImage_GetFileType(file.data()), file.data());
				FreeImage_FlipVertical(bitmap);

				if (FreeImage_GetBPP(bitmap) != 32)
				{
					FIBITMAP* const previous = bitmap;
					// FreeImage_ConverTo32Bits : do not delete previous bitmap
					bitmap = FreeImage_ConvertTo32Bits(bitmap);
					FreeImage_Unload(previous);
				}

				Image::Descriptor descriptor = Image::Descriptor();
				{
					descriptor.size.cx = FreeImage_GetWidth(bitmap);
					descriptor.size.cy = FreeImage_GetHeight(bitmap);

					Pipeline::Texture::Create(descriptor.handle, descriptor.size, FreeImage_GetBits(bitmap));
				}
				{
					size_t const x = file.find_first_of('/') + sizeof(char);
					size_t const y = file.find_last_of('.');

					Image::Storage.try_emplace(file.substr(x, y - x), descriptor);
				}
				FreeImage_Unload(bitmap);
			}
		}

		void Component::Draw()
		{
			using namespace Pipeline;
			{
				matrix<4, 4> const world = Translation(Location) * Rotation(Angle) * Scale(Length);
				Transform::Update<Transform::Type::Former>(reinterpret_cast<Transform::matrix const&>(world));

				matrix<4, 4> const projection = Scale(vector<2>(2.0f / 1280.0f, 2.0f / 720.0f));
				matrix<4, 4> const view = Rotation(0) * Translation(vector<2>(0, 0));
				matrix<4, 4> const camera = projection * view;
				Transform::Update<Transform::Type::Latter>(reinterpret_cast<Transform::matrix const&>(camera));
			}
			{
				Descriptor const& image = Storage.at(Content);

				Texture::Render(image.handle, {0, 0, image.size.cx, image.size.cy });
			}
		}
	}

	namespace Pipeline
	{
		void Procedure(HWND const, UINT const, WPARAM const, LPARAM const);
	}

	void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParameter, LPARAM const lParameter)
	{
		switch (uMessage)
		{
			case WM_CREATE:
			{
				Pipeline::Procedure(hWindow, uMessage, wParameter, lParameter);

				FreeImage_Initialise();
				Image::Import("Image/Background.png");
				Image::Import("Image/Cookie.png");
				FreeImage_DeInitialise();
				return;
			}
			case WM_APP:
			{
				Pipeline::Procedure(hWindow, uMessage, wParameter, lParameter);
				return;
			}
			case WM_DESTROY:
			{
				Pipeline::Procedure(hWindow, uMessage, wParameter, lParameter);
				return;
			}
			case WM_SIZE:
			{
				Pipeline::Procedure(hWindow, uMessage, wParameter, lParameter);
				return;
			}
		}
	}
}
