#pragma once
namespace Input
{
	namespace Get 
	{
		namespace Key
		{
			bool Down(size_t const code);
			bool Press(size_t const code);
			bool Up(size_t const code);
		}

		namespace Cursor
		{
			long X();
			long Y();
		}

		namespace Wheel
		{
			long H();
			long V();
		}
	}
}