class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        long long count = 0;
        int prev = nums[0], left = 0, right = 0;
        while (right < nums.size()) {
            if (prev != nums[right]) {
                count += (right - left + 1);
            } else {
                left = right;
                count++;
            }
            prev = nums[right++];
        }
        return count;
    }
};