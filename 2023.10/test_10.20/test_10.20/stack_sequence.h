#pragma once

namespace lys
{
	//˳�����ʵ��ջ
	template<class T, int Capacity = 100>//T��ʾԪ��,������ģ�����Capacity������ͨ�������޸Ĵ�С
	class stack
	{
	public:
		stack() {}

		~stack() {};

		void push(const T& x)
		{//ע���쳣����
			if (Capacity == top_idx + 1)
				throw "ջ�������޷�����";
			top_idx++;
			a[top_idx] = x;
		}

		void pop()
		{//ע���쳣����
			if (top_idx == -1)
				throw "ջΪ�գ��޷�ɾ��";
			top_idx--;
		}

		const T& top() const
		{//ע���쳣����
			if (top_idx == -1)
				throw "ջΪ�գ�û������";
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