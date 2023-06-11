#include<iostream>
#include<string>
#include "БъЭЗ.h"
using namespace std;

int main()
{
	int n1, n2, n3;
	int a[20];
	double b[20];
	string c[20];

	cin >> n1;
	for (int i = 0; i < n1; i++)
		cin >> a[i];
	cin >> n2;
	for (int i = 0; i < n2; i++)
		cin >> b[i];
	cin >> n3;
	for (int i = 0; i < n3; i++)
		cin >> c[i];

	cout << Max(a, n1) << endl;
	cout << Max(b, n2) << endl;
	cout << Max(c, n3) << endl;
	return 0;
}

