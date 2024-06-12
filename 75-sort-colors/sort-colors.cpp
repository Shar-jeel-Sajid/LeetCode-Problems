class Solution {
public:
    int sortColor(vector<int>& nums,int color = 0,int start = 0){
        int zeros = 0;
        for(int j = nums.size()-1;j > start;){
            if(nums[start++] == color){
                zeros++;
                continue;
            }
            while(nums[j] != color && j >= start)j--;
            if(j >= start){
                zeros++;
                nums[j] = nums[start-1];
                nums[start-1] = color;
            }
        }
        return zeros;
    }

    void sortColors(vector<int>& nums) {
        int start = sortColor(nums);
        sortColor(nums,1,start);
    }
};