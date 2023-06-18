#include <vector>
#include <string>
#include <iostream>
#include "function.h"


using namespace std;

// ʹ��vector��push_back��������vectorβ������
void push_back(vector<string>& v, const string& str);
// ʹ��vector��insert��������posָ���λ�ò���  
void insert(vector<string>& v, const vector<string>::iterator& pos, const string& str);
// ����vector�������Ԫ�أ��м��ÿո����
void print(vector<string>& v);

// ʹ��vector��erase������ɾ��posָ���Ԫ�� 
void erase(vector<string>& v, const vector<string>::iterator& pos);
// ʹ��vector��pop_back������ɾ��β��Ԫ��
void pop_back(vector<string>& v);


int main() {
	vector<string> v1;
	vector<string> v2 = { "Thursday", "me" };

	for (auto it = v2.begin(); it != v2.end(); it++) {
		push_back(v1, *it);
	}

	push_back(v1, "50");

	insert(v1, v1.begin(), "Crazy");
	insert(v1, v1.begin() + 2, "V");
	print(v1);
	cout << "vector size: " << v1.size() << endl;

	erase(v1, v1.end() - 1);
	print(v1);
	cout << "vector size: " << v1.size() << endl;

	pop_back(v1);
	print(v1);
	cout << "vector size: " << v1.size() << endl;

	return 0;
}
