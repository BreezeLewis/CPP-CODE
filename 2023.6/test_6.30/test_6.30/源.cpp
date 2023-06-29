#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s)
    {
        int left = 0, right = s.size() - 1;
        while (left <= right)
        {
            swap(s[left], s[right]);
            left++, right--;
        }

        // for(auto it = s.begin(); it != s.end(); it++)
        // {
        //     cout << *it << " ";
        // }
    }
};

int main()
{
    vector<char> s = { 'h','e','l','l','o' };
    auto it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    Solution().reverseString(s);

    it = s.begin();

    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;

    return 0;
}