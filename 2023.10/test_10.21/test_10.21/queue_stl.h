#pragma once
#include <queue>
using namespace std;

//��stlʵ�ֶ��У�ûʲô���༼�ɣ���queue�Ľӿ�ʵ��myqueue����
template<class T>
class myqueue
{
public:
	myqueue() {};
	~myqueue() {};

	void push(const T& x)
	{
		q.push(x);
	}

	void pop()
	{//ע���쳣����
		if (q.empty())
			throw "����Ϊ�գ��޷�ɾ��";
		q.pop();
	}

	const T& front() const
	{//ע���쳣����
		if (q.empty())
			throw "����Ϊ�գ��޷���ȡ";
		return q.front();
	}

	const T& back() const
	{//ע���쳣����
		if (q.empty())
			throw "����Ϊ�գ��޷���ȡ";
		return q.back();
	}

	size_t size() const
	{
		return q.size();
	}

	bool empty() const
	{
		return q.empty();
	}

private:
	queue<T> q;
};
