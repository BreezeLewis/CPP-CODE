#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main() {
    string s;
    set<string> words;

    while (cin >> s) 
    {
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';
        }

        stringstream ss(s);
        while (ss >> word) words.insert(word);
    }

    for (const auto& w : words) cout << w << endl;

    return 0;
}
