#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::swap;
using std::endl;
namespace Lewis
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& s);
		friend istream& operator>>(istream& in, string& s);
	public:
		typedef char* iterator;

		iterator begin();

		iterator end();

		string(const char* s = "");//构造函数、默认构造
		
		string(const string& s);//拷贝构造:普通写法

		string& operator=(const string& s);//赋值重载

		~string();//析构函数

		char& operator[](size_t pos);

		const char& operator[](size_t pos) const;
		
		size_t size() const;
		
		size_t capacity() const;

		bool empty()const;

		const char* c_str() const;

		void swap(string& s);

		void reserve(size_t n);

		void resize(size_t n, char ch = '\0');

		string& append(const string& s);

		string& append(size_t n, char ch);
		
		string& push_back(char ch);

		string& operator+=(const string& s);

		string& operator+=(char ch);

		string& insert(size_t pos, char ch);

		string& insert(size_t pos, const string& s);

		string& erase(size_t pos, size_t len = npos);

		size_t find(char ch, size_t pos = 0)const;

		size_t find(const string& s, size_t pos = 0)const;

		void clear();

		bool operator<(const string& s);

		bool operator<=(const string& s);

		bool operator>(const string& s);

		bool operator>=(const string& s);

		bool operator==(const string& s);

		bool operator!=(const string& s);


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		const static size_t npos = -1;
	};

	string::iterator string::begin()
	{
		return _str;
	}

	string::iterator string::end()
	{
		return _str + _size;
	}

	string::string(const char* s)//构造函数、默认构造
	{
		_size = _capacity = strlen(s);
		_str = new char[_capacity + 1];
		strcpy(_str, s);
	}

	string::string(const string& s)//拷贝构造:普通写法
		:_size(s._size),
		_capacity(s._capacity)
	{
		_str = new char[_capacity + 1];
		strcpy(_str, s._str);
	}

	string& string::operator=(const string& s)
	{
		if(this != &s)
		{
			string tmp(s);
			swap(tmp);
		}
		return *this;
	}

	string::~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

	char& string::operator[](size_t pos)
	{
		assert(pos < _size);
		return _str[pos];
	}

	const char& string::operator[](size_t pos) const
	{
		assert(pos < _size);
		return _str[pos];
	}

	size_t string::size() const 
	{
		return _size;
	}

	size_t string::capacity() const
	{
		return _capacity;
	}

	bool string::empty() const
	{
		return _size == 0;
	}

	const char* string::c_str() const
	{
		return _str;
	}

	void string::swap(string& s)
	{
		std::swap(_str, s._str);
		std::swap(_size, s._size);
		std::swap(_capacity, s._capacity);
	}

	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_capacity = n;
			_str = tmp;
		}
	}
	
	void string::resize(size_t n, char ch)
	{
		if (n > _size)
		{
			reserve(n);
			for (size_t i = _size; i < n; i++)
				_str[i] = ch;
			_size = n;
			_str[_size] = '\0';
		}
		else
		{
			_str[n] = '\0';
			_size = n;
		}
	}

	string& string::append(const string& s)
	{
		if (s.size() + _size > _capacity)
		{
			reserve(s.size() + _size);
		}

		strcpy(_str + _size, s.c_str());
		_size += s.size();
		return *this;
	}

	string& string::append(size_t n, char ch)
	{
		while(n--)
			push_back(ch);
		return *this;
	}

	string& string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newCapacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
		return *this;
	}

	string& string::operator+=(const string& s)
	{
		append(s);
		return *this;
	}

	string& string::operator+=(char ch)
	{
		push_back(ch);
		return *this;
	}

	string& string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);

		if (_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 4 : 2 * _capacity;
			reserve(newCapacity);
		}

		for (size_t i = _size + 1; i > pos; i--)
			_str[i] = _str[i - 1];

		_str[pos] = ch;
		++_size;

		return *this;
	}

	string& string::insert(size_t pos, const string& s)
	{
		assert(pos <= _size);

		if (s.size() + _size > _capacity)
		{
			reserve(s.size() + _size);
		}

		for (size_t i = _size + s.size(); i > pos; i--)
			_str[i] = _str[i - s.size()];

		strncpy(_str + pos, s.c_str(), s.size());
		_size += s.size();

		return *this;
	}

	string& string::erase(size_t pos, size_t len)
	{
		if (pos + len > _size || len == npos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else//需要移动数据
		{
			for (size_t i = pos + len; i <= size(); i++)
				_str[i - len] = _str[i];
			_size -= len;
		}

		return *this;
	}

	size_t string::find(char ch, size_t pos)const
	{
		assert(pos < _size);
		for (size_t i = pos; i < size(); i++)
			if (_str[i] == ch)
				return i;

		return npos;
	}

	size_t string::find(const string& s, size_t pos)const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, s.c_str());
		if (ptr == nullptr)
			return npos;

		return ptr - _str;
	}

	void string::clear()
	{
		_size = 0;
		_str[0] = '\0';
	}

	bool string::operator<(const string& s)
	{
		return !((*this) >= s);
	}

	bool string::operator<=(const string& s)
	{
		return !((*this) > s);
	}

	bool string::operator>(const string& s)
	{
		size_t len = _size < s.size() ? _size : s.size();
		for (size_t i = 0; i < len; i++)
		{
			if (_str[i] > s[i])
				return true;
			else if (_str[i] < s[i])
				return false;
		}
		return false;
	}

	bool string::operator>=(const string& s)
	{
		return ((*this) > s) || ((*this) == s);
	}

	bool string::operator==(const string& s)
	{
		if (_size != s.size())
			return false;
		for (size_t i = 0; i < _size; i++)
			if (_str[i] != s[i])
				return false;
		return true;
	}

	bool string::operator!=(const string& s)
	{
		return !((*this) == s);
	}

	ostream& operator<<(ostream& out, const string& s)
	{
		return out << s._str;
	}

	istream& operator>>(istream& in, string& s)
	{
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}

		return in;
	}

	void test_string1()
	{
		string s1("hello world");
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		for (size_t i = 0; i < s1.size(); i++)
			s1[i]++;

		cout << s1 << endl;

		auto it = s1.begin();
		while (it != s1.end())
		{
			(*it)--;
			it++;
		}

		cout << s1 << endl;

		for (auto& e : s1)
			cout << e;
	}

	void test_string2()
	{
		string s1("hello");
		s1 += " ";
		s1 += ' ';
		s1 += "world";
		cout << s1 << endl;
	}

	void test_string3()
	{
		string s1("helloworld");
		cout << s1.c_str() << endl;

		s1.insert(5, ' ');
		cout << s1.c_str() << endl;

		s1.insert(0, 'x');
		cout << s1.c_str() << endl;

		string s2("helloworld");
		cout << s2.c_str() << endl;
		s2.insert(5, " + ");
		cout << s2.c_str() << endl;

		s2.insert(0, "hello ");
		cout << s2.c_str() << endl;

		s2.insert(0, "x");
		cout << s2.c_str() << endl;

		string s3;
		s3.insert(0, "");
		cout << s3.c_str() << endl;
	}

	void test_string4()
	{
		string s1("hello hello world");
		s1.erase(0, 6);
		cout << s1.c_str() << endl;

		s1.erase(5);
		cout << s1.c_str() << endl;
	}

	void test_string5()
	{
		string s1("hello world");
		s1.resize(5);
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;
		cout << s1.c_str() << endl << endl;

		string s2("hello world");
		//s2.resize(15);
		s2.resize(15, 'x');
		cout << s2.size() << endl;
		cout << s2.capacity() << endl;
		cout << s2.c_str() << endl << endl;

		string s3("hello world");
		s3.resize(20, 'x');
		cout << s3.size() << endl;
		cout << s3.capacity() << endl;
		cout << s3.c_str() << endl << endl;
	}

	void test_string6()
	{
		/*std::string s1("hello world");
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		s1.insert(5, 1, '\0');
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		cout << s1 << endl;
		cout << s1.c_str() << endl; */

		/*string s1("hello world");
		cout << s1 << endl;
		cout << s1.c_str() << endl;

		s1.insert(5, '\0');
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		cout << s1 << endl;
		cout << s1.c_str() << endl;*/

		/*	char ch1, ch2;
			cin >> ch1 >> ch2;*/
		string s1;
		cin >> s1;
		cout << s1 << endl;


		string s2;
		cin >> s2;
		cout << s2 << endl;

		string s3;
		cin >> s3;
		cout << s3 << endl;
	}
}

