#pragma once

namespace Lewis
{
	template<typename T>
	class vector
	{
	public:
		//迭代器
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() { return _start; }
		iterator begin() const { return _start; }

		iterator end() { return _finish; }
		iterator end() const { return _finish; }

		const_iterator cbegin() { return _start; }
		const_iterator cbegin() const { return _start; }

		const_iterator cend() { return _finish; }
		const_iterator cend() const { return _finish; }

		//构造函数、析构函数
		vector() :_start(nullptr), _finish(nullptr), _endofstorage(nullptr) {}

		vector(int n, const T& value = T())//防止错误匹配到迭代器区间初始化
			:_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			reserve(n);
			while (n--) { push_back(value); }
		}

		vector(size_t n, const T& value = T())
			:_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			reserve(n);
			while (n--) { push_back(value); }
		}

		template<typename InputInterator>
		vector(InputInterator first, InputInterator last)//迭代器区间构造
			:_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			while (first != last) { push_back(*first); ++first; }
		}

		vector(const vector& x)//拷贝构造
			:_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			vector<T> ret(x.begin(), x.end());
			swap(ret);
		}

		vector<T>& operator=(vector<T> v)//很少情况会出现v1 = v1这种情况，此时损耗了性能
		{
			swap(v);
			return *this;
		}

		~vector()//析构函数
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		//capacity
		size_t size() const { return _finish - _start; }
		size_t capacity() const { return _endofstorage - _start; }
		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldSize = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0; i < oldSize; i++)
						tmp[i] = _start[i];
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + oldSize;
				_endofstorage = _start +n;
			}
		}

		void resize(size_t n, const T& value = T())
		{
			if (n > capacity())
				reserve(n);
			if (n > size())
				while (_finish < _start + n)
					(*_finish) = value, ++_finish;
			else
				_finish = _start + n;
		}

		//access
		T& operator[](size_t pos) { assert(pos < size());  return _start[pos]; }
		const T& operator[](size_t pos) const { assert(pos < size()); return _start[pos]; }

		//modify
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
				reserve(capacity() == 0 ? 4 : 2 * size());
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			//assert(!empty());
			if (!empty())
				_finish--;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		iterator insert(iterator pos, const T& x)//Return value An iterator that points to the first of the newly inserted elements.
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _endofstorage)
			{
				//这里扩容有会导致迭代器失效，需要重新处理
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * size());
				pos = _start + len;
			}


			iterator it = end();
			while (it > pos)
			{
				*it = *(it - 1);
				--it;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)//An iterator pointing to the new location of the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.
		{
			assert(pos >= _start);
			assert(pos < _finish);
			assert(!empty());

			iterator it = pos;
			while (it < _finish)
				*it = *(it + 1), ++it;
			--_finish;
			return pos;
		}

		void clear() { _finish = _start; }

		bool empty() const { return _finish == _start; }

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		for (size_t i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
			cout << *it << " ", ++it;
		cout << endl;

		it = v.begin();
		for (auto& e : v)
			cout << e << " ";
		cout << endl;

		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();
		v.pop_back();

		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}
	void test_vector2()
	{
		vector<int> v;
		v.resize(10, -1);
		for (auto& e : v)
			cout << e << " ";
		cout << endl;

		v.resize(5);
		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		for (auto& e : v)
			cout << e << " ";
		cout << endl;

		v.insert(v.begin(), 0);
		for (auto& e : v)
			cout << e << " ";
		cout << endl;

		vector<int>::iterator it = find(v.begin(), v.end(), 3);
		if (it != v.end())
			v.insert(it, 30);
		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int>::iterator it = find(v.begin(), v.end(), 3);
		if (it != v.end())
			v.insert(it, 30);

		//(*it)++;

		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		auto it = find(v.begin(), v.end(), 3);
		if (it != v.end())
			v.erase(it);

		//cout << *it << endl;

		//(*it)++;      一致认为迭代器失效

		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	//void test_vector6()//注意迭代器失效问题
	//{//要求删除所有偶数
	//	std::vector<int> v;
	//	v.push_back(1);
	//	v.push_back(2);
	//	v.push_back(2);
	//	v.push_back(2);
	//	v.push_back(2);
	//	v.push_back(3);
	//	v.push_back(4);
	//	v.push_back(4);
	//	v.push_back(4);
	//	v.push_back(4);

	//	for (auto& e : v)
	//		cout << e << " ";
	//	cout << endl;
	//	auto it = v.begin();
	//	while (it != v.end())
	//		if (*it % 2 == 0)
	//			it = v.erase(it);
	//		else
	//			it++;
	//	for (auto& e : v)
	//		cout << e << " ";
	//	cout << endl;
	//}

	void test_vector6()
	{//要求删除所有偶数
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);
		v.push_back(4);

		for (auto& e : v)
			cout << e << " ";
		cout << endl;
		auto it = v.begin();
		while (it != v.end())
			if (*it % 2 == 0)
				it = v.erase(it);
			else
				it++;
		for (auto& e : v)
			cout << e << " ";
		cout << endl;
	}

	void test_vector7()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);

		vector<int> v1(v);
		for (auto& e : v1)
			cout << e << " ";
		cout << endl;

		vector<int> v2;
		v2.push_back(10);
		v2.push_back(20);
		v1 = v2;
		for (auto& e : v1)
			cout << e << " ";
		cout << endl;

		v1 = v1;
		for (auto& e : v1)
			cout << e << " ";
		cout << endl;
	}

	void test_vector8()
	{
		std::string s("hello");
		vector<int> v(s.begin(), s.end());

		for (auto& e : v)
			cout << e << " ";
		cout << endl;

		vector<int> v1(10, 1);
		for (auto& e : v1)
			cout << e << " ";
		cout << endl;
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < vv.size(); ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	void test_vector9()
	{
		/*	vector<vector<int>> vvRet = Solution().generate(5);

			for (size_t i = 0; i < vvRet.size(); ++i)
			{
				for (size_t j = 0; j < vvRet[i].size(); ++j)
				{
					cout << vvRet[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;*/

		vector<vector<int>> vv;
		vector<int> v(5, 1);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}