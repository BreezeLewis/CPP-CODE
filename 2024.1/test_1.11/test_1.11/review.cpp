#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	int max_sum = nums[0];
	int cur_sum = nums[0];

	for (int i = 0; i < nums.size(); i++)
	{
		if (cur_sum < 0)
			cur_sum = nums[i];
		else
			cur_sum += nums[i];

		if (cur_sum > max_sum)
			max_sum = cur_sum;
	}

	return max_sum;
}

void generateEquation(int idx, int r, int n, vector<int>& bounds, vector<int>& solutions, int& totalSolutions)
{
	if (idx == n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += solutions[i];

		if (sum == r)
		{
			cout << "(";
			for (int i = 0; i < n; i++)
			{
				cout << solutions[i];
				if (i != n - 1)
					cout << ",";
			}
			cout << ")" << endl;
			totalSolutions++;
		}
		return;
	}

	for (int i = bounds[idx]; i <= r; i++)
	{
		solutions[idx] = i;
		generateEquation(idx + 1, r, n, bounds, solutions, totalSolutions);
	}
}

class Graph
{
	int V;
	vector<vector<int>> adj;
public:
	void addEdge(int u, int v)
	{

	}
};

int main()
{


	return 0;
}