#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string text, pattern;

	cin >> text >> pattern;

	vector<int> next(pattern.size(), 0);

	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];

		if (pattern[i] == pattern[j])
			j++;

		next[i] = j;
	}

	j = 0;

	for (int i = 0; i < text.size(); i++)
	{
		while (j > 0 && text[i] != pattern[j])
			j = next[j - 1];

		if (text[i] == pattern[j])
			j++;

		if (j == pattern.size())
		{
			cout << i - j + 1 + 1<< endl;
			j = next[j - 1];
		}
	}

	for (const auto& e : next)
		cout << e << " ";

	cout << endl;

	return 0;
}