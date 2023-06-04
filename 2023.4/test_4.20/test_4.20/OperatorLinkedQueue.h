<<<<<<< HEAD
#ifndef OPERATORLINKEDQUEUE_H
#define OPERATORLINKEDQUEUE_H
#include <iostream>
using namespace std;


class OperatorLinkedQueue {

private:
	int* arr;
	int size;
	int front;
	int back;

public:

	OperatorLinkedQueue();
	OperatorLinkedQueue(const OperatorLinkedQueue& other);
	~OperatorLinkedQueue();

	int GetSize() const;

	int& operator[] (const int& index);
	int operator[] (const int& index) const;
	OperatorLinkedQueue operator= (const OperatorLinkedQueue& right);
	OperatorLinkedQueue operator+= (const int& ele);
	OperatorLinkedQueue operator-- ();
	OperatorLinkedQueue operator-- (int);

	friend ostream& operator << (ostream& os, const OperatorLinkedQueue& object);
};

#endif

=======
#ifndef OPERATORLINKEDQUEUE_H
#define OPERATORLINKEDQUEUE_H
#include <iostream>
using namespace std;


class OperatorLinkedQueue {

private:
	int* arr;
	int size;
	int front;
	int back;

public:

	OperatorLinkedQueue();
	OperatorLinkedQueue(const OperatorLinkedQueue& other);
	~OperatorLinkedQueue();

	int GetSize() const;

	int& operator[] (const int& index);
	int operator[] (const int& index) const;
	OperatorLinkedQueue operator= (const OperatorLinkedQueue& right);
	OperatorLinkedQueue operator+= (const int& ele);
	OperatorLinkedQueue operator-- ();
	OperatorLinkedQueue operator-- (int);

	friend ostream& operator << (ostream& os, const OperatorLinkedQueue& object);
};

#endif

>>>>>>> cb73fa683f44cfac30efa94f2b3548a5d45d7a6c
