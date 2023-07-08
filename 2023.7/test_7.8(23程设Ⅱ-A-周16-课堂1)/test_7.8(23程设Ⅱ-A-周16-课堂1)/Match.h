#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool Matched(const string& s, const int& length)
{
    stack<char> st;
    for (auto& e : s)
    {
        if (e == '(' || e == '{' || e == '[')
        {//»Î’ª
            st.push(e);
        }
        else if (e == ')')
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else return false;
        }
        else if (e == '}')
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else return false;
        }
        else if (e == ']')
        {
            if (!st.empty() && st.top() == '[')
                st.pop();
            else return false;
        }
    }
    return st.empty();
}