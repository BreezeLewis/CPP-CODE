#pragma once
#include <stack>
using namespace std;

//��stl��ʵ��ջ,ûʲô���ɣ�ֱ����stack�Ľӿ����mystack
template<class T>//T��ʾԪ������
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
	{//ע���쳣����
		if (st.empty())
			throw "ջΪ�գ��޷�ɾ��";
		st.pop();
	}

	const T& top() const
	{//ע���쳣����
		if (st.empty())
			throw "ջΪ�գ�û������";
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
