#pragma once
#include "vector.h"

// transform, image
namespace Rendering
{
	namespace Image
	{
		class Component final
		{
		public :
			void Draw();

		public :
			char const* Content = nullptr;

		public :
			vector<2> Length	= { 0, 0 };
			float	  Angle		= { 0 };
			vector<2> Location	= { 0, 0 };
		};
	}
};

