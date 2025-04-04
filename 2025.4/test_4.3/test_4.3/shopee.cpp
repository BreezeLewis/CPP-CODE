#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//class Solution {
//public:
//    typedef long long ll;
//    bool pick(ll sum, int left, int right, vector<int>& nums)
//    {
//        if (sum == 0) return true;
//
//        for (int i = right; i >= left; i--)
//        {
//            // ��ѡi
//            if (sum - nums[i] < 0) //˵���϶�����ѡ��С�������������Ҫ
//                continue;
//            int res = pick(sum - nums[i], left, right - 1, nums);
//            if (res == true) return true;
//        }
//        return false;
//    }
//    bool IsPartition(vector<int>& nums) {
//        // write code here
//        if (nums.size() < 2) return false;
//        sort(nums.begin(), nums.end());
//        ll sum = 0;
//        for (int i = 0; i < nums.size(); i++) sum += nums[i];
//        if (sum % 2 == 1) return false;
//
//        ll half = sum >> 1;
//        ll tmp = nums[nums.size() - 1];
//        if (half == tmp) return true;
//
//        // ˼·����������ѡ��ʣ�µĶ��п���
//        return pick(half - nums[nums.size() - 1], 0, nums.size() - 2, nums); // ��nums��������Ϊ һ������ ����
//
//        
//    }
//};




class Solution {
public:
    /**
     * Note: ���������������������Ѿ�ָ���������޸�
     *
     *
     *
     * @param generated_map int���� vector<vector<>>
     * @return int����
     */
    int res = 1;
    int dx[4] = { 1,-1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int n = 0;
    vector<vector<int>> vis;

    void dfs(vector<vector<int> >& vv, int x, int y)
    {
        for (int i = 0; i < 4; i++)
        {
            int sx = x + dx[i], sy = y + dy[i];
            if (sx < 0 || sx >= n || sy < 0 || sy >= n) continue;
            if (vv[sx][sy] == 1) continue;
            if (!vis[sx][sy])
            {
                vis[sx][sy] = true;
                dfs(vv, sx, sy);
                res++;
            }

        }
    }

    int apply(vector<vector<int>>& generated_map) {
        // write code here
        // 0�ɴ1���ɴ�
        n = generated_map.size();
        vector<vector<int>> emp(n, vector<int>(n, 0));
        vis = emp;

        dfs(generated_map, 0, 0);

        return n * n - res;
    }
};



int main()
{
    vector<vector<int>> nums = { {0,0,0,0},{1,0,0,1},{0,0,1,0},{0,0,0,1} };
    cout << Solution().apply(nums) << endl;
}