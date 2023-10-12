#include <iostream>

using namespace std;

namespace lys
{
	template<class T>
	class list
	{
		
	};

	template<class T>
	struct node
	{
		node* next;

		T data;
	};

	int main()
	{
		node<int>* heada = nullptr;
		node<int>* headb = nullptr;

		node<int>* tail = heada;
		while (tail->next)
			tail = tail->next;

		while (headb)
		{
			tail->next = headb;
			tail = tail->next;
			headb = headb->next;
		}

	}
}
