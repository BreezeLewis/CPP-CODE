#include <vector>
#include <string>
#include <iostream>
#include "function.h"


using namespace std;

// 使用vector的push_back函数，在vector尾部插入
void push_back(vector<string>& v, const string& str);
// 使用vector的insert函数，在pos指向的位置插入  
void insert(vector<string>& v, const vector<string>::iterator& pos, const string& str);
// 遍历vector输出所有元素，中间用空格隔开
void print(vector<string>& v);

// 使用vector的erase函数，删除pos指向的元素 
void erase(vector<string>& v, const vector<string>::iterator& pos);
// 使用vector的pop_back函数，删除尾部元素
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
