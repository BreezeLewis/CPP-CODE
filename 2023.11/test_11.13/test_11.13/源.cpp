#include <iostream>
#include <vector>

using namespace std;

// 函数用于计算最大子序列和
void maxSubArray(vector<int>& nums)
{
    int n = (int)nums.size();
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start = 0, end = 0;
    int temp_start = 0;

    for (int i = 1; i < n; i++)
    {
        if (current_sum < 0)
        {
            current_sum = nums[i];
            temp_start = i;
        }
        else
        {
            current_sum += nums[i];
        }

        if (current_sum > max_sum)
        {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }

    // 输出结果
    cout << max_sum << endl;
    //cout << start + 1 << " " << end + 1 << endl << endl;
}

int main()
{
    int T = 1;
    //cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
        vector<int> sequence(N);

        // 读取序列S
        for (int i = 0; i < N; i++)
        {
            cin >> sequence[i];
        }

        // 输出结果
        //cout << "Case " << t << ":" << endl;
        maxSubArray(sequence);
    }

    return 0;
}


/*
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
*/