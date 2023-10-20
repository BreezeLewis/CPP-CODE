#pragma once
#include <stack>
using namespace std;

//用stl来实现栈,没什么技巧，直接用stack的接口完成mystack
template<class T>//T表示元素类型
class mystack
{
public:
	mystack() {}

	~mystack() {};

	void push(const T& x)
	{
		st.push(x);
	}

	void pop()
	{//注意异常处理
		if (st.empty())
			throw "栈为空，无法删除";
		st.pop();
	}

	const T& top() const
	{//注意异常处理
		if (st.empty())
			throw "栈为空，没有数据";
		return st.top();
	}

	size_t size() const
	{
		return st.size();
	}

	bool empty() const
	{
		return st.empty();
	}


private:
	stack<T> st;
};
