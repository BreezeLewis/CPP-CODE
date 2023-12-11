#include <iostream>
#include <vector>
#include <set>
using namespace std;

int  N;
int vv[10][10];
int main()
{
    set<pair<int, int>> s;
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> vv[i][j];
                if (vv[i][j])
                    s.insert(make_pair(i, j));
            }
        bool flag = true;
        for (auto it1 = s.begin(); it1 != s.end(); it1++)
            for (auto it2 = s.begin(); it2 != s.end(); it2++)
            {
                if (it1->second == it2->first)
                {
                    pair<int, int> p = make_pair(it1->first, it2->second);
                    if (s.find(p) == s.end())
                        flag = false;
                }
            }

        //cout << (flag == true ? "Yes" : "No") << endl;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}