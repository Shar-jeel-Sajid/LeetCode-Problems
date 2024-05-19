class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> parities(n,0);
        bool parity = nums[n-1]%2;
        for(int i = n-1;i >= 0;i--){
            if(nums[i]%2 == parity)
                parities[i] = i;
            else
                parities[i] = parities[i+1];
            parity = nums[i]%2;
        }
        n = queries.size();
        vector<bool> ans(n,0);
        for(int i = 0;i < n;i++)
            ans[i] = parities[queries[i][0]] >= queries[i][1];
        return ans;
    }
};