#include <iostream>
using namespace std;
template<typename Type>
Type Max(const Type& a, const Type& b)

{

	cout << "This is Max<Type>" << endl;

	return a > b ? a : b;

}

template<>

int Max<int>(const int& a, const int& b)

{

	cout << "This is Max<int>" << endl;

	return a > b ? a : b;

}

template<>

char Max<char>(const char& a, const char& b)

{

	cout << "This is Max<char>" << endl;

	return a > b ? a : b;

}

int Max(const int& a, const int& b)

{

	cout << "This is Max" << endl;

	return a > b ? a : b;

}

int main()

{

	Max(10, 20);

	Max(12.34, 23.45);

	Max('A', 'B');

	Max<int>(20, 30);

	return 0;

}