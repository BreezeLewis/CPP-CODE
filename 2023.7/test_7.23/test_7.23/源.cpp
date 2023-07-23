#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
void removeDuplicates(list<T>& aList)
{
	T curValue;
	
	typename list<T>::iterator cur, p;
	
	cur = aList.begin();
	while (cur != aList.end())
	{
		curValue = *cur;
		p = ++cur;//¿Õ°×ÐÐ 1
		p = cur + 2;
		while (p != aList.end())
		{
			if (*p == curValue)
			{
				p == cur ? cur = p = aList.erase(p) : p = aList.erase(p);//¿Õ°×ÐÐ 2
			}
			else
			{
				p++;
			}
		}
	}
}


int main()

{

	int ar[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	int n = sizeof(ar) / sizeof(int);

	list<int> mylist(ar, ar + n);

	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);//4 3 2 1 0 5 6 7 8 9

	reverse(pos, mylist.end());//4 3 2 1 0 9 8 7 6 5

	list<int>::const_reverse_iterator crit = mylist.crbegin();

	while (crit != mylist.crend())

	{

		cout << *crit << " ";

		++crit;

	}

	cout << endl;

}