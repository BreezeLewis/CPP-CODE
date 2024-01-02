#include <iostream>
#include <vector>
using namespace std;

void maxSumArray(vector<int>& nums)
{
	int n = (int)nums.size();
	int sum = nums[0];
	int current_sum = nums[0];
	int start = 0, end = 0;
	int current_start = 0;

	for (int i = 1; i < n; i++)
	{
		if (current_sum < 0)
		{
			current_sum = nums[i];
			current_start = i;
		}
		else
			current_sum += nums[i];

		if (current_sum > sum)
		{
			sum = current_sum;
			start = current_start;
			end = i;
		}
	}

	cout << sum << " ";

	cout << start + 1 << " " << end + 1 << endl << endl;
}

int main()
{
	int T;
	cin >> T;
	int cnt = 0;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int> nums(N, 0);
		for (int i = 0; i < N; i++)
			cin >> nums[i];
		printf("Case %d:\n", ++cnt);
		maxSumArray(nums);
	}

	return 0;
}