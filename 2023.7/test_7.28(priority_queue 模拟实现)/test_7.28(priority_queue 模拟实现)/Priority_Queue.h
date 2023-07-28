#pragma once
#include <vector>
namespace Lewis
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y) const
		{
			return x < y;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	private:
		Container _con;
		Compare _cmp;
	public:
		priority_queue(){}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			_con(first, last);
		}

		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

		const T& top() const
		{
			return _con[0];
		}

		void adjust_up(size_t child)
		{
			size_t parent = (child - 1) / 2;
			while (child)
			{
				if (_cmp(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			adjust_up(size() - 1);
		}

		void adjust_down(size_t parent)
		{
			size_t child = parent * 2 + 1;

			while (child < size())
			{
				if (child + 1 < size() && _cmp(_con[child], _con[child + 1]))
					child++;

				if (_cmp(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}

		void pop()
		{
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
	};
}