#include <map>
#include <string>
#include <utility>
#include "function.h"

using namespace std;

void insert(map<string, int>& m, const string& key, int val);
void insert(map<string, int>& m, const pair<string, int>& p);
map<string, int>::iterator find(map<string, int>& m, const string& key);
void erase(map<string, int>& m, const string& key);
void erase(map<string, int>& m, const map<string, int>::iterator& pos);
// {key: val, key: val, key: val} 
void print(const map<string, int>& m);


int main() {
	map<string, int> m = { {"hello", 1}, {"hi", 2} };
	insert(m, "www", 3);
	insert(m, make_pair("h", 4));
	print(m);

	erase(m, "hello");
	print(m);

	map<string, int>::iterator pos = find(m, "www");
	if (pos != m.end()) {
		erase(m, pos);
	}
	print(m);

	return 0;
}
