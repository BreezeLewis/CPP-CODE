////////#include <iostream>
////////#include <list>
////////using std::list;
////////using std::cout;
////////using std::endl;
////////
////////int main()
////////{
////////    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
////////    list<int> list1(arr + 1, arr + 7);//2,3,4,5,6,7
////////    list<int> list2(arr, arr + 6);//1,2,3,4,5,6
////////    list<int> list3(list1);//2,3,4,5,6,7
////////    if (list1 == list3)
////////        cout << "true" << endl;
////////    else
////////        cout << "false" << endl;
////////    if (list1 < list2)
////////    {
////////        cout << "list1 < list2" << endl;
////////    }
////////    else if (list1 > list2)
////////    {
////////        cout << "list1 > list2" << endl;
////////    }
////////    else
////////    {
////////        cout << "list1 == list2" << endl;
////////    }
////////    return 0;
////////}
//////
//////#include <iostream>
//////#include <map>
//////#include <string>
//////using std::map;
//////using std::string;
//////using std::cout;
//////using std::endl;
//////
//////int main()
//////{
//////    map<string, int> m1 = { {"hello",0} };
//////    m1.insert({ "my",2 });
//////    m1["cat"] = 10;
//////
//////    for (auto it = m1.begin(); it != m1.end(); it++)
//////    {
//////        cout << it->first << " " << it->second << endl;
//////    }
//////    return 0;
//////}
////
////
//////#include <iostream>
//////#include <map>
//////#include <utility>
//////#include <string>
//////using std::multimap;
//////using std::make_pair;
//////using std::string;
//////using std::cout;
//////using std::endl;
//////
//////int main()
//////{
//////    multimap<string, int> m1 = { {"hello",0} };
//////    m1.insert({ "hello",1 });
//////    m1.insert(make_pair("hello", 2));
//////    m1.insert({ "hi",3 });
//////
//////    cout << m1.count("hello") << endl;
//////
//////    for (auto it = m1.find("hello"); it != m1.end(); it++)
//////    {
//////        cout << it->first << " " << it->second << endl;
//////    }
//////
//////    m1.erase("hello");
//////    cout << m1.size() << endl;
//////    return 0;
//////}
////
////
////
////#include <iostream>
////#include <stack>
////#include <deque>
////#include <string>
////using std::stack;
////using std::deque;
////using std::string;
////using std::cout;
////using std::endl;
////
////int main()
////{
////    deque<int> deq = { 1,2,3,4 };
////    stack<int> s1(deq);
////    s1.push(22);
////    cout << s1.top() << endl;
////    while (!s1.empty())
////    {
////        cout << s1.top() << " ";
////        s1.pop();
////    }
////    return 0;
////}
//
//#include <iostream>
//#include <queue>
//#include <deque>
//#include <string>
//#include <vector>
//#include <algorithm>
//using std::vector;
//using std::queue;
//using std::deque;
//using std::string;
//using std::cout;
//using std::endl;
//
//int main()
//{
//   /* deque<int> deq = { 1,2,3,4 };
//    queue<int> que(deq);
//    que.push(5);
//    que.push(6);
//    cout << que.front() << " ";
//    cout << que.back() << endl;
//    que.pop();
//    cout << que.front() << " ";
//    cout << que.back() << endl;*/
//    vector<int> vec = { 22,1,34,55,2 };
//    auto it = vec.begin();
//    it = vec.erase(it + 2);
//
//    //cout << *(vec.rbegin()) << endl;
//    return 0;
//}

#include <iostream>
using namespace std;
class Test {
public:
	int x;
	Test() { this->x = 0; }
	Test(int x = 1) { this->x = x; }
};

int main() {
	Test* t = new Test();
	cout << t->x << endl;
	return 0;
}