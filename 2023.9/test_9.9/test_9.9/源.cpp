#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    struct cmp
    {
        bool operator()(const pair<string, int> x, const pair<string, int> y)
        {
            return (x.second > y.second) && (x.first < y.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k)
    {
        map<string, int> m;

        for (auto& e : words)
            m[e]++;

        vector<pair<string, int>> ret(m.begin(), m.end());

        vector<string> res;

        sort(ret.begin(), ret.end(), cmp());

        for (int i = 0; i < k; i++)
            res.push_back(ret[i].first);

        return res;
    }
};
int main()
{
    vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
    int k = 2;
    Solution().topKFrequent(words, k);

	return 0;
}