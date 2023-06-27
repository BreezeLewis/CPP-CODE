//#include <iostream>
//using namespace std;
//
//class Solution
//{
//public:
//    void reverse(string& s, int left, int right)
//    {
//        while (left <= right)
//        {
//            swap(s[left], s[right]);
//            left++, right--;
//        }
//    }
//    string reverseStr(string s, int k)
//    {
//        int left = 0, right = s.size() > k ? (k - 1) : s.size() - 1;
//        while (left < s.size() && left < right)
//        {
//            reverse(s, left, right);
//            left = right + 1;
//            right = s.size() - left > k ? (left + k - 1) : s.size() - 1;
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    string s;
//    int k;
//    cin >> s >> k;
//    s = Solution().reverseStr(s, k);
//    cout << s;
//
//}
#include <iostream>
using namespace std;
//int main()
//{
//
//	string a = "hello world";
//
//	string b = a;//Éî¿½±´
//
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//
//	else cout << "false" << endl;
//
//	string c = b;
//
//	c = "";
//
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	a = "";
//
//	if (a.c_str() == b.c_str())
//	{
//		cout << "true" << endl;
//	}
//	else cout << "false" << endl;
//
//	return 0;
//}

int main()

{

	string str("Hello Bit.");

	str.reserve(111);

	str.resize(5);

	str.reserve(50);

	cout << str.size() << ":" << str.capacity() << endl;

	return 0;

}