#include <iostream>
using namespace std;
int main()

{

	string a = "hello world";

	string b = a;

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string c = b;

	c = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	a = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	return 0;

}