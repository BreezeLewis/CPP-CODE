#pragma once

namespace lys
{
	//顺序表来实现栈
	template<class T, int Capacity = 100>//T表示元素,非类型模板参数Capacity，可以通过传参修改大小
	class stack
	{
	public:
		stack() {}

		~stack() {};

		void push(const T& x)
		{//注意异常处理
			if (Capacity == top_idx + 1)
				throw "栈已满，无法插入";
			top_idx++;
			a[top_idx] = x;
		}

		void pop()
		{//注意异常处理
			if (top_idx == -1)
				throw "栈为空，无法删除";
			top_idx--;
		}

		const T& top() const
		{//注意异常处理
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
}