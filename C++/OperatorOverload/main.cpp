#include "Vector.h"

int main()
{
	Vector vec1 = Vector(1.f, 1.f) + Vector(1.f, 1.f);
	vec1.PrintVector();

	Vector vec2 = Vector(1.f, 1.f) + 1.5f;
	vec2.PrintVector();

	cout << "Vector +=" << endl;
	vec1 += vec2;
	vec1.PrintVector();

	cout << "Vector -=" << endl;
	vec1 -= vec2;
	vec1.PrintVector();

	cout << "Vector *=" << endl;
	vec1 *= vec2;
	vec1.PrintVector();

	cout << "Vector /=" << endl;
	vec1 /= vec2;
	vec1.PrintVector();

	cout << "Vector ++" << endl;
	vec1++;
	vec1.PrintVector();

	cout << "Vector --" << endl;
	vec1--;
	vec1.PrintVector();

	return 0;
}