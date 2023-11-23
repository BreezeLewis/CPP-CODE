#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
/*
the set of objects studied in discrete mathematics can be finite or infinite the term finite mathematics is sometimes applied to parts of the field of discrete mathematics that deals with finite sets particularly those areas relevant to business
the set of objects studied in discrete mathematics can be finite or infinite the term finite mathematics is sometimes applied to parts of the field of discrete mathematics that deals with finite sets particularly those areas relevant to business
*/
class Greater
{
public:
	bool operator()(pair<int,char> x, pair<int, char> y)
	{
		return x.first > y.first;
	}
};


int main()
{
	priority_queue <pair<int, char>, vector<pair<int, char>>, Greater> pq;
	unordered_map<char, int> um;
	string s = "the set of objects studied in discrete mathematics can be finite or infinite the term finite mathematics is sometimes applied to parts of the field of discrete mathematics that deals with finite sets particularly those areas relevant to business";
	for (const auto& e : s)
	{
		um[e]++;
	}

	for (const auto& e : um)
	{
		pq.push(make_pair(e.second, e.first));
	}

	{
		auto ret(pq);
		while (!ret.empty())
		{
			cout << ret.top().second << ":" << ret.top().first << endl;
			ret.pop();
		}
	}

	return 0;
}