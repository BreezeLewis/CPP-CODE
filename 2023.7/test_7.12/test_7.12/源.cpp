#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v.push_back(x);
    }
    set<double> s;
    while (v.size())
    {
        int min = v[0], max = v[0];
        //int mini=0,maxi=0;
        for (size_t i = 0; i < v.size(); i++)
        {
            if (v[i] < min)
            {
                min = v[i];
            }
            if (v[i] > max)
            {
                max = v[i];
            }
        }
        double mid = (max + min) / 2.0;
        s.insert(mid);
        auto it = find(v.begin(), v.end(), min);
        v.erase(it);
        it = find(v.begin(), v.end(), max);
        v.erase(it);
    }
    cout << s.size() << endl;
    return 0;
}