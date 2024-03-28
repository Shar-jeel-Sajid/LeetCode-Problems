class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, size = 0, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (++freq[nums[i]] <= k) {
                size++;
                continue;
            }
            if (max < size)
                max = size;
            while (nums[left] != nums[i]) {
                freq[nums[left++]]--;
            }
            freq[nums[left++]]--;
            size = i - left + 1;
        }
        return size > max ? size : max;
    }
};