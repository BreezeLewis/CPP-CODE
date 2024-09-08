#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#include <stdio.h>

const int N = 1e9;

int b = 1000000;

int main ()
{
	/*{
		int a = 0;
		
		cout << a;
		{
			int a = 5;

			cout << a;
		}

		cout << a;
	}*/

	int b = 10;

	cout << b << endl;

	{
		int a = 0; 
		
		b = 0;

		cout << b << endl;

		int b;

		b = 100;

		{
			b = 1000;

			int b = 10000;

			b = 99;

		}

		b = 88;

		int c;

		int x;
	}

	b = 77;

	return 0;
}