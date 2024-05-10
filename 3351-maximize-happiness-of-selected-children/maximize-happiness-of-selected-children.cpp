class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        for(int i = 0;i < happiness.size();i++){
            if(i > happiness[i])
                happiness[i] = 0;
            else
                happiness[i] -= i;
        }
        long long sum = 0;
        for(int i = 0;i < k;i++)
            sum += happiness[i];
        return sum;
    }
};