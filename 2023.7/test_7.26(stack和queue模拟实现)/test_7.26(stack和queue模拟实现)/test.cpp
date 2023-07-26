#include <iostream>
#include <deque>
using namespace std;

#include "Stack.h"
#include "Queue.h"

int main()
{
	Lewis::stack<int> st;

	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}
	cout << endl;

	return 0;
}

//int main()
//{
//	Lewis::queue<int> q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//
//	while (!q.empty())
//	{
//		cout << q.front() << endl;
//		q.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

//int main()
//{
//	deque<int> d;
//	d.push_back(1);
//	d.push_back(2);
//	d.push_back(3);
//	d.push_back(4);
//
//	d.push_front(10);
//	d.push_front(20);
//
//	for (size_t i = 0; i < d.size(); ++i)
//	{
//		cout << d[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}