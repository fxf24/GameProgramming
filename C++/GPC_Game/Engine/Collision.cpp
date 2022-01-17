#define _USE_MATH_DEFINES

#include "vector.h"

namespace Collision
{
	struct Point final
	{
		vector<2> Location;
	};

	struct Circle final
	{
		float     Diameter; 
		vector<2> Location;
	};

	struct RectAngle final
	{
		vector<2> Length;
		float Angle;
		vector<2> Location;
	};

	inline matrix<2, 2> Rotation(float const& angle)
	{
		float constexpr radian = static_cast<float>(M_PI) / 180.0f;

		return matrix<2, 2>
		{
			+cos(angle * radian), +sin(angle * radian),
			-sin(angle * radian), +cos(angle * radian)
		};
	}

	bool Collide(Point const& LHS, Point const& RHS)
	{ return (length(LHS.Location - RHS.Location) == 0); }

	bool Collide(Point const& LHS, Circle const& RHS)
	{ return length(LHS.Location - RHS.Location) <= RHS.Diameter / 2; }
	
	bool Collide(Circle const& LHS, Point const& RHS)
	{ Collide(RHS, LHS); }
	
	bool Collide(Point const& LHS, RectAngle const& RHS)
	{
		if (RHS.Angle == 0)
		{
			vector<2> const min = RHS.Location - RHS.Length / 2;
			vector<2> const max = RHS.Location + RHS.Length / 2;

			return
				(
					min[0] <= LHS.Location[0] and LHS.Location[0] <= max[0] and
					min[1] <= LHS.Location[1] and LHS.Location[1] <= max[1]
				);
		}
		else
		{
			return Collide
			(
				Point    {                LHS.Location * Rotation(-RHS.Angle) },
				RectAngle{ RHS.Length, 0, RHS.Location * Rotation(-RHS.Angle) }
			);
		}
	}
	
	bool Collide(RectAngle const& LHS, Point const& RHS)
	{ return Collide(RHS, LHS); }
	
	bool Collide(Circle const& LHS, Circle const& RHS)
	{ return length(LHS.Location - RHS.Location) <= (LHS.Diameter + RHS.Diameter) / 2; }
	
	bool Collide(Circle const& LHS, RectAngle const& RHS)
	{
		if (RHS.Angle == 0)
		{
			vector<2> const min = RHS.Location - RHS.Length / 2;
			vector<2> const max = RHS.Location + RHS.Length / 2;

			if (
				(min[0] <= LHS.Location[0] and LHS.Location[0] <= max[0]) or
				(min[1] <= LHS.Location[1] and LHS.Location[1] <= max[1])
			   )
			{
				return Collide
				(
					Point    {												   LHS.Location },
					RectAngle{ RHS.Length + vector<2>(1, 1) * LHS.Diameter, 0, RHS.Location }
				);
			}
			else
			{
				Point target = Point();
				     if (LHS.Location[0] >= RHS.Location[0] and LHS.Location[1] >= RHS.Location[1]) target.Location = { max[0], max[1] };
				else if (LHS.Location[0] <= RHS.Location[0] and LHS.Location[1] >= RHS.Location[1]) target.Location = { min[0], max[1] };
				else if (LHS.Location[0] <= RHS.Location[0] and LHS.Location[1] <= RHS.Location[1]) target.Location = { min[0], min[1] };
				else if (LHS.Location[0] >= RHS.Location[0] and LHS.Location[1] <= RHS.Location[1]) target.Location = { max[0], min[1] };

				return Collide(LHS, target);
			}
		}
		else
		{
			return Collide
			(
				Circle    { LHS.Diameter,  LHS.Location * Rotation(-RHS.Angle) },
				RectAngle { RHS.Length, 0, RHS.Location * Rotation(-RHS.Angle) }
			);
		}
	}

	bool Collide(RectAngle const& LHS, Circle const& RHS)
	{ return Collide(RHS, LHS); }
	
	bool Collide(RectAngle const& LHS, RectAngle const& RHS)
	{
		if (LHS.Angle == 0.0f and RHS.Angle == 0.0f)
		{
		}
		else if (abs(LHS.Angle - RHS.Angle) < 0.1f)
		{
		}
		else 
		{
		}
	}
}
