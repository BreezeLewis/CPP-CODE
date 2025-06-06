#pragma once

//定义链表节点
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
	{//在链表尾部插入，注意异常处理
		node* newnode = new node(x);
		if (head == nullptr)//如果链表为空
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
	{//在链表头部删除，注意异常处理
		if (_size == 0)
			throw "队列为空，无法删除";

		node* del = head;
		head = head->next;
		delete del;
		
		_size--;
	}

	const T& front() const
	{
		return head->data;//返回队头数据
	}

	const T& back() const
	{
		return tail->data;//返回队尾数据
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