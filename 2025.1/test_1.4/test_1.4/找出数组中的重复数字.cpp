class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        for (auto x : nums)
            if (x < 0 || x >= n)
                return -1;
        for (int i = 0; i < n; i++) {
            while (nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
            if (nums[i] != i) return nums[i];
        }
        return -1;
    }
};
