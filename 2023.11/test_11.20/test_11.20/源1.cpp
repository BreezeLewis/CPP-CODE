
#include <iostream>

#include <string>
#include <unordered_map>
using namespace std;

string find_tel(unordered_map<string, string>& um, string& name)
{
    auto it = um.find(name);
    if (it == um.end())
        return "No";
    else
        return it->first;
}

int main()
{
    int n;
    cin >> n;
    string s;
    unordered_map<string, string> um;
    while (n--)
    {
        cin >> s;
        int pos = s.find(',');
        string name = s.substr(0, pos);
        string tel = s.substr(pos + 1);
        um.insert(make_pair(name, tel));
    }

    cin >> n;
    string name;
    while (n--)
    {
        cin >> name;
        cout << name << ":";
        cout << find_tel(um, name) << endl;
    }

    return 0;
}