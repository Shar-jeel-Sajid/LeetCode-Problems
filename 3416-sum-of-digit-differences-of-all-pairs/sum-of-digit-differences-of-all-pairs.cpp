class Solution {
public:
    long long findSum(vector<int>& freq){
        long long sum = 0;
        for(int i = 1;i < freq.size();i++){
            sum += freq[i]*freq[i-1];
            freq[i] += freq[i-1];
        }
        return sum;
    }

    long long sumDigitDifferences(vector<int>& nums) {
        long long sum = 0;
        int k = 1,tmp = nums[0];
        while(tmp/=10)
            k++;
        for(int i = 0;i < k;i++){
            vector<int> freq(10,0);
            for(int& j:nums){
                freq[j%10]++;
                j/=10;
            }
            sum += findSum(freq);
        }
        return sum;
    }
};