class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long product = 1;
        int countZero = 0;
        vector<int> answers;
        for(int i = 0;i < nums.size();i++){
            if(nums[i])
                product *= nums[i];
            else {
                countZero++;
            }
        }
        for(int i = 0;i < nums.size();i++) {
            if(nums[i]) {
                if(!countZero)
                    answers.push_back(product/nums[i]);
                else
                    answers.push_back(0);
            }
            else {
                if(countZero == 1)
                    answers.push_back(product);
                else
                    answers.push_back(0);
            }
        }
        return answers;
    }
};