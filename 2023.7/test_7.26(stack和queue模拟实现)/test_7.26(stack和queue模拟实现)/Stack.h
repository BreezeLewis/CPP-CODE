#pragma once
namespace Lewis
{
	template<class T, class Container = deque<T>>
	class stack
	{
	private:
		Container _con;
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T& top() const
		{
			return _con.back();
		}
		size_t size() const
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	};
}