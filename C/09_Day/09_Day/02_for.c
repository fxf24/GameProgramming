#include <stdio.h>

int main()
{
	///    *
	///   ***
	///  *****
	/// *******
	/// </summary>
	/// <returns></returns>

	// 개행용
	for (int i = 0; i < 5; i++) {
		// 공백용
		for (int j = 1; j < 5 - i; j++) {
			printf("  ");
		}
		// * 용
		for (int k = 0; k < (i * 2) + 1; k++) {
			printf(" *");
		}
		printf("\n");
	}

	return 0;
}