#pragma once
#include "vector.h"

// transform, image
namespace Rendering
{
	class Camera final
	{
	public :
		void Set() const;

	public :
		vector<2> Length = { 1280, 720 };
		float	  Angle = { 0 };
		vector<2> Location = { 0, 0 };
	};

	namespace Text
	{
		class Component final
		{
		public :
			void Draw();

		public :
			char const* str = nullptr;

			struct
			{
				char const* Name		  = nullptr;
				unsigned	Size		  = 0;
				bool		Bold		  = false;
				bool		Italic		  = false;
				bool		Underline	  = false;
				bool		StrikeThrough = false;
			}Font;

			struct
			{
				unsigned char Red = 0;
				unsigned char Green = 0;
				unsigned char Blue = 0;

			}Color;

		public :
			vector<2> Length = { 0.0f, 0.0f };
			vector<2> Location = { 0.0f, 0.0f };
		};
	}

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

	namespace Tilemap
	{
		enum class Tile
		{
			Empty,
			Ground,
			Wall,
			Door,
			Portal
		};

		class Component final
		{
		public:
			Component() = default;
			Component(char const* c, vector<2> len, vector<2> loc, Tile t)
			{
				Content = c;
				Length = len;
				Location = loc;
				tile = t;
			}

		public:
			void Draw();

		public:
			char const* Content = nullptr;

		public:
			vector<2> Length = { 0, 0 };
			float	  Angle = { 0 };
			vector<2> Location = { 0, 0 };
			Tile tile = Tile::Empty;
		};
	}

	namespace Animation
	{
		enum class View {
			idle,
			front,
			back,
		};

		class Component final
		{
		public:
			void Draw();
			bool GetDirection();

		public:
			char const* Content = nullptr;
			float rollTime = 0;
			float Playback = 0;
			float Duration = 0;
			bool Repeatable = false;
			bool direction = false;

		public:
			vector<2> Length = { 0, 0 };
			float	  Angle = { 0 };
			vector<2> Location = { 0, 0 };

			View view = View::idle;
			View GetView() { return view; }
		};
	}
};

