#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n = 10000;
	for (int i = 5; i <= n; i++)
	{
		string a = to_string(i);
		string b = to_string(i * i);
		if (b.substr(b.size() - a.size()) == a)
			cout << a << "��" << b << "��ͬ����" << endl;
	}

	return 0;
}