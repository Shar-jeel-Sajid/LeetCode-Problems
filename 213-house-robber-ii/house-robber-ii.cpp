class Solution {
public:
    int robLinear(vector<int> nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        nums[2] += nums[0];
        for (int i = 3; i < n; i++)
            nums[i] += max(nums[i - 2], nums[i - 3]);
        return max(nums[n - 1], nums[n - 2]);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        return max(robLinear(vector<int>(nums.begin() + 1, nums.end())),
                   robLinear(vector<int>(nums.begin(), nums.end() - 1)));
    }
};