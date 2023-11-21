#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int arr[] = { 8,7,5,3,3,2,1 };
	vector<int> v;
	for (auto& e : arr)
	{
		v.push_back(e);
	}

	bool ans = binary_search(v.begin(), v.end(), 1);
	cout << ans << endl;

	return 0;
}