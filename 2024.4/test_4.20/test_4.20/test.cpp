#include <iostream>

using namespace std;

int main()
{
	double matrix[64][128];

	for (int i = 0; i < 64; i++)
		for (int j = 0; j < 128; j++)
		{
			matrix[i][j] = 10.0;
		}

	return 0;
}