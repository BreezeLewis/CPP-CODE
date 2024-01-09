#include <iostream>
#include <vector>
using namespace std;

void maxSubSequence(vector<int>& nums)
{
	int n = (int)nums.size();
	int max_sum = nums[0], cur_sum = nums[0];
	int cur_start = 0, start = 0, end = 0;

	for (int i = 1; i < n; i++)
	{
		if (cur_sum < 0)
		{
			cur_sum = nums[i];
			cur_start = i;
		}
		else
			cur_sum += nums[i];

		if (cur_sum > max_sum)
		{
			max_sum = cur_sum;
			start = cur_start;
			end = i;
		}
	}

	cout << max_sum << " ";
	//cout << start + 1 << " " << end + 1 << endl << endl;
}

int main()
{
	int T = 1;
	//cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int N;
		cin >> N;
		vector<int> nums(N, 0);
		for (int i = 0; i < N; i++)
			cin >> nums[i];

		//cout << "Case " << i << ":" << endl;
		maxSubSequence(nums);
	}

	return 0;
}