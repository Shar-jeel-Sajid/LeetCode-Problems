class Solution {
public:
    int maxOperations(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int sum = nums[0] + nums[1], count = 1;
        for(int i = 2;i < nums.size();i+=2)
            if(nums[i] + nums[i+1] == sum)
                count++;
            else
                break;
        return count;
    }
};