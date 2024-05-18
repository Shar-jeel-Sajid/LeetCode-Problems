class Solution {
public:
    int numTrees(int n) {
        vector<int> ans (n+1,1);
        for(int i = 2;i <= n;i++){
            int sum = 0;
            for(int j = 1;j <= i;j++){
                sum += (ans[i-j]*ans[j-1]);
            }
            ans[i] = sum;
        }
        return ans[n];
    }
};