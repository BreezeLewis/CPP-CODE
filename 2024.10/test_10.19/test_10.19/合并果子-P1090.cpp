#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int, vector<int>, greater<int>> heap;

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		heap.push(x);
	}

	int res = 0;
	while (heap.size() > 1)
	{
		int a = heap.top(); heap.pop();
		int b = heap.top(); heap.pop();
		res += a + b;
		heap.push(a + b);
	}

	cout << res << endl;
	return 0;
}