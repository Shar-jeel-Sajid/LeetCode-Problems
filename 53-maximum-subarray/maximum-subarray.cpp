class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > 0)
                nums[i + 1] += nums[i];
            if (nums[i + 1] > max)
                max = nums[i + 1];
        }
        for (int& i : nums)
            cout << i;
        return max;
    }
};