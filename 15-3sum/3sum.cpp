class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l,r,target;
        set<vector<int>> st;
        
        vector<int> v;
        for(int i=0;i<n-2;i++){
            l=i+1;
            r=n-1;
            target=-1*nums[i];
            while(l<r){
                if(nums[l]+nums[r]==target){
                    v={nums[i],nums[l],nums[r]};
                    st.insert(v);
                    // ans.push_back(v);
                    l++;
                }
                else if(nums[l]+nums[r]<target) l++;
                else r--;
            }
            
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};