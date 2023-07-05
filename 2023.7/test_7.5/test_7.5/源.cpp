//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//	v.insert(it, 10);
//	for (auto& e : v)
//		cout << e << " ";
//	/*while (it != v.end())
//	{
//		if (*it != 0)
//			cout << *it;
//		else
//			v.erase(it);
//		it++;
//	}*/
//	return 0;
//}


//#include <iostream>
//#include <vector>
//using std::vector;
//using std::cout;
//using std::endl;
//
//int main()
//{
//    int ia[5] = { 1,2,3,4,5 };
//    vector<int> vec1(ia + 1, ia + 4);//2/3/4
//    vector<int> vec2(4, 2);//2,2,2,2
//
//    cout << vec1[2] << endl;//4
//    cout << vec2.at(0) << endl;//2
//
//    vec1.insert(vec1.begin(), 2, 10);//10,10,2,3,4,5
//    vec2.insert(vec2.end(), ia, ia + 3);//2,2,2,2,1,2,3
//
//    cout << vec1.front() << endl;//10
//    cout << vec2.back() << endl;//3
//
//    return 0;
//}

//#include <iostream>
//#include <deque>
//#include <string>
//using std::deque;
//using std::string;
//using std::cout;
//using std::endl;
//
//int main()
//{
//    deque<string> deq;
//    deq.push_front("good");
//    deq.push_back("dog");
//    deq.insert(deq.begin(), "a");
//    deq.insert(deq.end(), "partner");
//
//    for (auto it = deq.begin(); it != deq.end(); it++)
//        cout << *it << " ";
//    cout << endl;
//    return 0;
//}

#include <iostream>
#include <deque>
using std::deque;
using std::cout;
using std::endl;

int main()
{
	deque<int> deq = { 0,1,2,3,4,5,6,7,8,9,10 };

	auto iter = deq.begin();
	deq.erase(deq.erase(deq.erase(iter + 2)));
	cout << deq.size() << endl;//0,1,3,5,7,8,9,10

	deq.erase(deq.end() - 2, deq.end());//0,1,,5,7,8

	for (auto it = deq.begin(); it != deq.end(); it++)
		cout << *it << " ";
	cout << endl;

	cout << deq.size() << endl;
	return 0;
}