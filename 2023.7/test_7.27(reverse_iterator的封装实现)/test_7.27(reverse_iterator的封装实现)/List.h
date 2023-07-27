#pragma once

namespace Lewis
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;
		
		list_node(const T& x) :_next(nullptr), _prev(nullptr), _data(x) {}
	};


	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		node* _pnode;

		__list_iterator(node* p) :_pnode(p) {}

		Ref operator*() { return _pnode->_data; }

		Ptr operator->() { return &_pnode->_data; }

		Self& operator++() { _pnode = _pnode->_next; return *this; }

		Self operator++(int)
		{
			Self tmp(*this);
			_pnode = _pnode->_next; 
			return tmp;
		}

		Self& operator--() { _pnode = _pnode->_prev; return *this; }
		Self operator--(int) 
		{ 
			Self tmp(*this);
			_pnode = _pnode->_prev; 
			return tmp; 
		}

		bool operator!=(const Self& l) const { return _pnode != l._pnode; }
		bool operator==(const Self& l) const { return _pnode == l._pnode; }
	};


	/*template<typename T>
	struct __list_iterator
	{
		typedef list_node<T> node;
		node* _pnode;

		__list_iterator(node* p) :_pnode(p) {}

		T& operator*() { return _pnode->_data; }

		__list_iterator<T>& operator++()
		{
			_pnode = _pnode->_next;
			return *this;
		}

		bool operator!=(const __list_iterator<T>& it) { return _pnode != it._pnode; }
	};*/

	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef Reverse_Iterator<iterator, T&, T*> reverse_iterator;
		typedef Reverse_Iterator<iterator, const T&, const T*> const_reverse_iterator;

		iterator begin() { return iterator(_head->_next); }
		iterator end() { return iterator(_head); }

		const_iterator begin() const { return const_iterator(_head->_next); }
		const_iterator end() const { return const_iterator(_head); }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rbegin() const { return reverse_iterator(end()); }
		const_reverse_iterator rend() const { return reverse_iterator(rbegin()); }

		void empty_initialize()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		list()
		{
			empty_initialize();
		}	

		template<typename InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_initialize();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		

		void swap(list<T>& l)
		{
			std::swap(_head, l._head);
			std::swap(_size, l._size);
		}

		list(const list<T>& l)
		{
			empty_initialize();

			for (const auto& e : l)
				push_back(e);
		}

		/*list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				clear();
				for (auto& e : l)
					push_back(e);
			}
			return *this;
		}*/

		//现代写法
		list<T>& operator=(list<T> l)
		{
			swap(l);
			return *this;
		}

		size_t size() const { return _size; }
		bool empty() const { return _size == 0; }

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			auto it = begin();
			while (it != end())
				it = erase(it);
		}

		iterator insert(iterator pos, const T& x)
		{
			node* newnode = new node(x);
			pos._pnode->_prev->_next = newnode;
			newnode->_prev = pos._pnode->_prev;
			newnode->_next = pos._pnode;
			pos._pnode->_prev = newnode;

			++_size;
			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node* next = pos._pnode->_next;
			node* prev = pos._pnode->_prev;

			prev->_next = next;
			next->_prev = prev;

			delete pos._pnode;

			--_size;
			return iterator(next);
		}

		void push_back(const T& x) { insert(end(), x); }

		void push_front(const T& x) { insert(begin(), x); }

		void pop_back() { erase(--end()); }

		void pop_front() { erase(begin()); }

	private:
		node* _head;
		size_t _size;
	};
	
	void test_list1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		list<int>::iterator it = l.begin();
		while (it != l.end())
			cout << *it << " ", ++it;
		cout << endl;

		for (auto& e : l)
			cout << e << " ";
		cout << endl;
	}

	void test_list2()
	{
		list<int> l;

		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);

		for (auto& e : l)
			cout << e << " ";
		cout << endl;

		l.pop_back();
		l.pop_back();
		l.pop_back();
		l.pop_back();
		for (auto e : l)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		l.push_back(5);
		l.push_back(6);

		for (auto& e : l)
			cout << e << " ";
		cout << endl;

		list<int> l1(l);
		for (auto& e : l1)
			cout << e << " ";
		cout << endl;

		list<int> l2;
		l2.push_back(10);
		l2.push_back(20);
		l2.push_back(30);
		l2.push_back(40);

		l = l2;
		for (auto& e : l)
			cout << e << " ";
		cout << endl;

	}
	
	void test_list4()
	{
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		list<int>::iterator it = lt1.begin();
		while (it != lt1.end())
		{
			(*it) += 2; // 可以写
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//print_list(lt1);
	}

	struct Pos
	{
		int _row;
		int _col;

		Pos(int row = 0, int col = 0)
			:_row(row)
			, _col(col)
		{}
	};

	void print_list(const list<Pos>& lt)
	{
		list<Pos>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//it->_row++;

			cout << it->_row << ":" << it->_col << endl;

			++it;
		}
		cout << endl;
	}

	void test_list5()
	{
		list<Pos> lt;
		Pos p1(1, 1);
		lt.push_back(p1);
		lt.push_back(p1);
		lt.push_back(p1);
		lt.push_back(Pos(2, 2));
		lt.push_back(Pos(3, 3));

		// int* p  -> *p
		// Pos* p  -> p->
		list<Pos>::iterator it = lt.begin();
		//list<Pos>::iterator it2 = it;
		while (it != lt.end())
		{
			it->_row++;

			//cout << (&(*it))->_row << ":" << (*it)._col << endl;
			cout << it->_row << ":" << it->_col << endl;
			//cout << it.operator->()->_row << ":" << it->_col << endl;

			++it;
		}
		cout << endl;

		print_list(lt);
	}
}