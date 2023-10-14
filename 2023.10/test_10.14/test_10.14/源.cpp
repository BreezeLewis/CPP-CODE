#include <iostream>
#include <string>
using namespace std;

struct node
{
	char data;
	node* next;
	node(char data)
	{
		this->data = data;
		next = nullptr;
	}
};

void Print(node* head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node* createList()
{
	string s;
	cin >> s;
	node* head = new node(s[0]);
	node* tail = head;
	for (int i = 1; i < s.size(); i++)
	{
		node* newnode = new node(s[i]);
		tail->next = newnode;
		tail = tail->next;
	}
	return head;
}

node* reverse(node* head)
{
	node* pre = nullptr;
	node* cur = head;
	node* next = head->next;
	while (cur)
	{
		cur->next = pre;
		if (next == nullptr)
			return cur;
		pre = cur;
		cur = next;
		if(next)
			next = next->next;
	}

	return cur;
}

int main()
{
	node* head = createList();

	Print(head);

	head = reverse(head);

	Print(head);

	return 0;
}