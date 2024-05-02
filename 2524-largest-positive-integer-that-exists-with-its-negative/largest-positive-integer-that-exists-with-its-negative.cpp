class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> neg;
        for(int &i:nums)
            if(i<0)
                neg.insert(i);
        int max = 0;
        for(int &i:nums)
            if(max < i && neg.find((-1)*i) != neg.end())
                max = i;
        return max ? max : -1;
    }
};