class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0,product = 1,count = 0;
        if(k<=1)
            return 0;
        for(int i = 0;i < nums.size();i++) {
            product *= nums[i];
            while(product >= k && product != 1)
                product /= nums[left++];
            count += (1+i-left);
        }
        return count;
    }
};