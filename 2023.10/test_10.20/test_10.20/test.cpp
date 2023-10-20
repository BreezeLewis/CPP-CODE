#include <iostream>
#include <string>
using namespace std;

//顺序表来实现栈
template<class T, int Capacity = 100>//T表示元素,非类型模板参数Capacity，可以通过传参修改大小
class stack
{
public:
	stack() {}

	~stack() {};

	void push(const T& x)
	{
		if (Capacity == top_idx + 1)
			throw "栈已满，无法插入";
		top_idx++;
		a[top_idx] = x;
	}

	void pop()
	{
		if (top_idx == -1)
			throw "栈为空，无法删除";
		top_idx--;
	}

	const T& top() const
	{
		if (top_idx == -1)
			throw "栈为空，没有数据";
		return a[top_idx];
	}

	size_t size() const
	{
		return top_idx + 1;
	}

	bool empty() const
	{
		return top_idx == -1;
	}


private:
	T a[Capacity];
	int top_idx = -1;
};

int main()
{
	int t, n;
	string x, cmd;
	cin >> t;
	
	while (t--)
	{
		stack<string, 100010> st;
		//mystack<string> st;
		cin >> n;
		while (n--)
		{
			cin >> cmd;
			if (cmd == "push")
			{
				cin >> x;
				st.push(x);
			}
			else if (cmd == "pop")
			{
				if (st.empty())
					cout << "Empty" << endl;
				else
					st.pop();
			}
			else if (cmd == "query")
			{
				if (st.empty())
					cout << "Anguei!" << endl;
				else
					cout << st.top() << endl;
			}
			else if (cmd == "size")
			{
				cout << st.size() << endl;
			}
		}
	}


	return 0;
}