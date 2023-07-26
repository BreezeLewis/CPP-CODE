#pragma once
namespace Lewis
{
	template<class T, class Container = deque<T>>
	class queue
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
			_con.pop_front();
		}
		const T& front() const
		{
			return _con.front();
		}
		const T& back() const 
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