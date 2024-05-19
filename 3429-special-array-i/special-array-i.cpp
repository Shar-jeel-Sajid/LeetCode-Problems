class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool ans = !(nums[0]%2);
        for(int& i:nums)
            if(ans != i%2)
                ans = !ans;
            else
                return false;
        return true;
    }
};