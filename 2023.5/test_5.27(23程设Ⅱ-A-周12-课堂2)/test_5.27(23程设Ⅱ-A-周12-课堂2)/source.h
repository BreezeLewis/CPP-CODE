#pragma once
#include <iostream>
using namespace std;
class Coding
{
public:
	Coding() {
		cout << "Coding constructor" << endl;
	}
	~Coding() {
		cout << "~Coding" << endl;
	}
};

class Exercising
{
public:
	Exercising() {
		cout << "Exercising constructor" << endl;
	}
	~Exercising() {
		cout << "~Exercising" << endl;
	}
};
class Weekend :public Coding, Exercising
{
public:
	Weekend() {
		cout << "Weekend constructor" << endl;
	}
	~Weekend() {
		cout << "~Weekend" << endl;
	}
};
class Workday :public Exercising, Coding
{
public:
	Workday() {
		cout << "Workday constructor" << endl;
	}
	~Workday() {
		cout << "~Workday" << endl;
	}
};
class Choseday :public Weekend
{
public:
	Choseday() {
		cout << "Workday constructor" << endl;
		cout << "Choseday constructor" << endl;
	}
	~Choseday() {

		cout << "~Choseday" << endl;
		cout << "~Workday" << endl;
	}
};