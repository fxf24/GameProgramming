#include <Windows.h>

#define _USE_MATH_DEFINES

#include <map>
#include <string>

#include "FreeImage.h"
#include "Pipeline.h"
#include "Rendering.h"

#include "Resource.h"
#include "Time.h"

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

	void Camera::Set() const
	{
		using namespace Pipeline;

		matrix<4, 4> const projection = Scale(vector<2>(2.0f / Length[0], 2.0f / Length[1]));
		matrix<4, 4> const view = Rotation(-Angle) * Translation(-Location);
		matrix<4, 4> const camera = projection * view;

		Transform::Update<Transform::Type::Latter>(reinterpret_cast<Transform::matrix const&>(camera));
	}

	namespace Text
	{
		void Import(std::string const& file)
		{
			AddFontResourceEx(file.data(), FR_PRIVATE | FR_NOT_ENUM, nullptr);
		}

		void Component::Draw()
		{
			LOGFONT descriptor = LOGFONT();

			descriptor.lfHeight    = Font.Size;
			descriptor.lfWeight    = Font.Bold ? FW_BOLD : FW_NORMAL;
			descriptor.lfItalic    = Font.Italic;
			descriptor.lfUnderline = Font.Underline;
			descriptor.lfStrikeOut = Font.StrikeThrough;
			descriptor.lfCharSet   = DEFAULT_CHARSET;
			// DEFAULT CHARSET : auto language

			strcpy_s(descriptor.lfFaceName, LF_FACESIZE, Font.Name);

			HFONT const font = CreateFontIndirect(&descriptor);

			SIZE  const area   = { static_cast<LONG>(  Length[0]), static_cast<LONG>(  Length[1]) };
			POINT const center = { static_cast<LONG>(Location[0]), static_cast<LONG>(Location[1]) };

			Pipeline::String::Render(font, str, RGB(Color.Red, Color.Green, Color.Blue), area, center);

			DeleteObject(font);
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
			}
			{
				Descriptor const& image = Storage.at(Content);

				Texture::Render(image.handle, {0, 0, image.size.cx, image.size.cy });
			}
		}
	}

	namespace Animation
	{
		struct Descriptor final
		{
		public:
			Pipeline::Texture::Handle* handle = nullptr;

		public:
			UINT Motion = UINT();
			SIZE Frame  = SIZE();
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

				Animation::Descriptor descriptor = Animation::Descriptor();
				{
					descriptor.Frame.cx = FreeImage_GetWidth(bitmap);
					descriptor.Frame.cy = FreeImage_GetHeight(bitmap);

					Pipeline::Texture::Create(descriptor.handle, descriptor.Frame, FreeImage_GetBits(bitmap));
				}
				{
					size_t const x = file.find_first_of('/') + sizeof(char);
					size_t const y = file.find_last_of('[');
					size_t const z = file.find_last_of(']');
					

					descriptor.Motion = stoi(file.substr(y + sizeof(char), z - (y + sizeof(char))));
					descriptor.Frame.cx /= descriptor.Motion;

					Animation::Storage.try_emplace(file.substr(x, y - x), descriptor);
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
			}
			{
				Descriptor & image = Storage.at(Content);

				LONG const progress = static_cast<LONG>((Playback / Duration) * image.Motion);

				RECT area;

				if (GetDirection())
				{
					area = {
						image.Frame.cx * (progress + 1), image.Frame.cy * 0,
						image.Frame.cx * (progress + 0), image.Frame.cy * 1
					};
				}
				else
				{
					area = {
						image.Frame.cx * (progress + 0), image.Frame.cy * 0,
						image.Frame.cx * (progress + 1), image.Frame.cy * 1
					};
				}

				Texture::Render(image.handle, area);
				
				float const delta = Time::Get::Delta();

				Playback += delta;

				if (Duration <= Playback) 
				{
					if (Repeatable)
					{
						Playback = fmod(Playback, Duration);
					}
					else
					{
						Playback -= delta;
					}
				}

			}
		}
		bool Component::GetDirection()
		{
			return direction;
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
				{
					Resource::Import("Image", Image::Import);
					Resource::Import("Animation", Animation::Import);
				}
				FreeImage_DeInitialise();

				Resource::Import("Font", Text::Import);
				return;
			}
			case WM_APP:
			{
				Pipeline::Procedure(hWindow, uMessage, wParameter, lParameter);
				return;
			}
			case WM_DESTROY:
			{
				for (auto const& pair : Image::Storage)
				{
					Pipeline::Texture::Delete(pair.second.handle);
				}

				for (auto const& pair : Animation::Storage)
				{
					Pipeline::Texture::Delete(pair.second.handle);
				}

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
