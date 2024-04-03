class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int min = INT_MAX , min2 = INT_MAX;
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] < min) {
                min2 = min;
                min = nums[i];
            }
            else if(nums[i] < min2)
                min2 = nums[i];
        }
        return nums[0] + min + min2;
    }
};