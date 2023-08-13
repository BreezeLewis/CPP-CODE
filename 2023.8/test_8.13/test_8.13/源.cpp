#include<iostream>
#include "container.h"
using namespace std;

int main()
{
	Container* p;
	double a, b, c1, c2;
	cin >> a >> b >> c1 >> c2;

	Cube A(a);
	Sphere B(b);
	Cylinder C(c1, c2);

	p = &A;
	cout << "Cube's area: " << p->calSurfaceArea() << ", volume: " << p->calVolume() << endl;
	p = &B;
	cout << "Sphere's area: " << p->calSurfaceArea() << ", volume: " << p->calVolume() << endl;
	p = &C;
	cout << "Cylinder's area: " << p->calSurfaceArea() << ", volume: " << p->calVolume() << endl;

	return 0;
}
