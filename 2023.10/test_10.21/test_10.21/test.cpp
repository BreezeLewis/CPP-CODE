#include <iostream>
using std::endl;
using std::cin;
using std::cout;

//��������ڵ�
template <class T>
struct Node
{
	Node(const T& x) :data(x), next(nullptr)
	{}
	T data;
	Node<T>* next;
};

template<class T>
class queue
{
	typedef Node<T> node;
public:
	queue()
	{
		head = nullptr;
		tail = nullptr;
		_size = 0;
	}

	~queue()
	{
		while (head)
		{
			node* next = head->next;
			delete head;
			head = next;
		}
	}

	void push(const T& x)
	{//������β�����룬ע���쳣����
		node* newnode = new node(x);
		if (head == nullptr)//�������Ϊ��
		{
			head = tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}

		_size++;
	}

	void pop()
	{//������ͷ��ɾ����ע���쳣����
		if (_size == 0)
			throw "����Ϊ�գ��޷�ɾ��";

		node* del = head;
		head = head->next;
		delete del;

		_size--;
	}

	const T& front() const
	{
		return head->data;//���ض�ͷ����
	}

	const T& back() const
	{
		return tail->data;//���ض�β����
	}

	size_t size()
	{
		return _size;
	}

	bool empty()
	{
		return _size == 0;
	}

private:
	node* head;
	node* tail;
	size_t _size;
};

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	int op;
	while (n--)
	{
		cin >> op;
		if (op == 1)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (op == 2)
		{
			if (q.empty())
				cout << "ERR_CANNOT_POP" << endl;
			else
				q.pop();
		}
		else if (op == 3)
		{
			if (q.empty())
				cout << "ERR_CANNOT_QUERY" << endl;
			else
				cout << q.front() << endl;
		}
		else if (op == 4)
		{
			cout << q.size() << endl;
		}
	}

	return 0;
}