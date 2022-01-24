#pragma once
namespace Rendering::Pipeline
{
	namespace Texture
	{
		void Create(struct Handle*& handle, SIZE const size, BYTE const* const data);
		void Render(struct Handle const* const& handle, RECT const area);
	}

	namespace Transform
	{
		enum class Type
		{
			Former,
			Latter,
		};

		using matrix = float[4][4];

		template<Type type>
		void Update(matrix const& matrix);
	}
};

