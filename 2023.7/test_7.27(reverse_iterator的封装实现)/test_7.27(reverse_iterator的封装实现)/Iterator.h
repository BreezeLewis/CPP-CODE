#pragma once
namespace Lewis
{
	template<class Iterator, class Ref, class Ptr>
	struct Reverse_Iterator
	{
		Iterator _it;
		typedef Reverse_Iterator<Iterator, Ref, Ptr> Self;
		
		Reverse_Iterator(Iterator(it)) :_it(it) {}

		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &operator*();
		}

		Self& operator++()
		{
			--_it;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp(*this);
			--_it;
			return tmp;
		}

		Self& operator--()
		{
			++_it;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			++_it;
			return tmp;
		}

		bool operator!=(const Self& x) const
		{
			return _it != x._it;
		}
		
		bool operator==(const Self& x) const
		{
			return _it == x._it;
		}
	};
}