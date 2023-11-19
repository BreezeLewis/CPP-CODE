#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//
//int is_match(string s)
//{
//    stack<char> st;
//    int n = (int)s.size();
//    for (int i = 0; i < n; i++)
//    {
//        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
//        {
//            st.push(s[i]);
//        }
//        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//        {
//            if (st.empty())
//                return 3;
//            if (s[i] == ')')
//            {
//                if (st.top() == '(')
//                    st.pop();
//                else
//                    return 1;
//            }
//            else if (s[i] == ']')
//            {
//                if (st.top() == '[')
//                    st.pop();
//                else
//                    return 1;
//            }
//            else if (s[i] == '}')
//            {
//                if (st.top() == '{')
//                    st.pop();
//                else
//                    return 1;
//            }
//        }
//    }
//    if (!st.empty())
//        return 2;
//    return 0;
//}
//
//int main()
//{
//
//
//    string s;
//    int n;
//    cin >> n;
//    getchar();
//    while (n--)
//    {
//        std::getline(std::cin, s);
//        cout << is_match(s) << endl;
//    }
//
//    return 0;
//}
///*
//4
//a * (b[1] * (x + y)
//let{ x = a[0) * (b + c); y = b }
//x[i] + y * (b - c)
//2 + 3
//*/
