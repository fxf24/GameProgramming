namespace Layout
{
	struct Vertex
	{
		float4 Position : POSITION;
		float4 Color	: COLOR;
	};

	struct Pixel
	{
		float4 Position : SV_POSITION;
		float4 Color	: COLOR;
	};
	
	typedef float4 Color;
}