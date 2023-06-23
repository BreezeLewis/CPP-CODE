//#include "string.h"
//using namespace Lewis;
//string::string(const char* s)//构造函数、默认构造
//{
//	_size = _capacity = strlen(s);
//	_str = new char[_capacity + 1];
//	strcpy(_str, s);
//}
//
//string::string(const string& s)//拷贝构造:普通写法
//	:_size(s._size),
//	_capacity(s._capacity)
//{
//	_str = new char[_capacity + 1];
//	strcpy(_str, s._str);
//}
//
//size_t string::size() const
//{
//	return _size;
//}
//
//size_t string::capacity() const
//{
//	return _capacity;
//}
//
//const char* string::c_str() const
//{
//	return _str;
//}
//
//void string::swap(string& s)
//{
//	std::swap(_str, s._str);
//	std::swap(_size, s._size);
//	std::swap(_capacity, s._capacity);
//}
//
//void string::reserve(int n)
//{
//	if (n > _capacity)
//	{
//
//	}
//}
//
//string& string::operator+=(string& s)
//{
//
//	return *this;
//}
//
//string& string::operator+=(char ch)
//{
//
//	return *this;
//}
//
//ostream& operator<<(ostream& out, const string& s)
//{
//	return out << s.c_str();
//}
//
//istream& operator>>(istream& in, string& s)
//{
//	char ch;
//	ch = in.get();
//	while (ch != ' ' || ch != '\n')
//	{
//		s += ch;
//	}
//
//	return in;
//}