#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	int n, cnt;
	cin >> n;
	int num = 1;
	string word;
	//int表示编号，map存储每个单词是否出现
	vector<pair<unordered_map<string, int>, int>> sentenceMap;
	while (n--)
	{
		pair<unordered_map<string, int>, int> map;
		map.second = num++;
		cin >> cnt;
		while (cnt--)
		{
			cin >> word;
			if (!map.first.count(word))
			{
				map.first[word]++;
			}
		}
		sentenceMap.push_back(map);
	}

	int t;
	cin >> t;
	while (t--)
	{
		int flag = 0;
		cin >> word;
		for (auto& e : sentenceMap)
		{
			if (e.first.count(word))
			{
				if (flag == 0)
					cout << e.second, flag = 1;
				else
					cout << " " << e.second;
			}
		}
		cout << endl;
	}

	return 0;
}