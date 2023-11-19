#include <iostream>
#include <map>
using namespace std;

void evaluator()
{
    int index = 0, ratio = 0, num = 0;
    map<int, int> m1;//第一项存幂，第二项存系数ratio
    //map<int, int> m2;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> ratio >> index;
        m1.insert(make_pair(index, ratio));
    }
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> ratio >> index;
        m1[index] += ratio;
        if (m1[index] == 0)
            m1.erase(index);
    }

    cout << m1.size() << endl;
    auto it = m1.rbegin();
    while (it != m1.rend())
    {
        cout << it->second << " " << it->first << endl;
        it++;
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        evaluator();
    }

    return 0;
}