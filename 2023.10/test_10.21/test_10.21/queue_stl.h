#pragma once
#include <queue>
using namespace std;

//用stl实现队列，没什么过多技巧，用queue的接口实现myqueue即可
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
	{//注意异常处理
		if (q.empty())
			throw "队列为空，无法删除";
		q.pop();
	}

	const T& front() const
	{//注意异常处理
		if (q.empty())
			throw "队列为空，无法获取";
		return q.front();
	}

	const T& back() const
	{//注意异常处理
		if (q.empty())
			throw "队列为空，无法获取";
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
