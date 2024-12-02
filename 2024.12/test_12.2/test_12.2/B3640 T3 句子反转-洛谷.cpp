#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;
string s;

int main()
{
	getline(cin, s);

	stringstream ss(s);

	while (ss)
	{
		string tmp;

		ss >> tmp;

		if (tmp == "") break;

		if (islower(tmp[0]))
			for (int i = 0; i < tmp.size(); i++) tmp[i] = toupper(tmp[i]);
		else if (isupper(tmp[0]))
			for (int i = 0; i < tmp.size(); i++) tmp[i] = tolower(tmp[i]);
		else 
			reverse(tmp.begin(), tmp.end());

		v.push_back(tmp);

	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

	return 0;
}