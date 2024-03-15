class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums;
        vector<int> answers;
        answers.push_back(1);
        answers.push_back(nums[0]);
        for(int i = 2;i < nums.size();i++)
            answers.push_back(answers[i-1]*nums[i-1]);
        vector<int> right;
        for(int i=0;i<nums.size();i++)
            right.push_back(1);
        right[right.size()-2]=(nums[nums.size()-1]);
        for(int i = nums.size()-2;i >= 0;i--)
            right[i] = nums[i+1]*right[i+1];
        for(int i = 0;i < answers.size();i++)
            answers[i] *= right[i];
        return answers;
        
    }
};