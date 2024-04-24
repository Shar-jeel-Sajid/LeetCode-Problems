class Solution {
public:
    int tribonacci(int n) {
        int seq[3] = {0,1,1};
        if(n < 3)
            return seq[n];
        for(int i = 2;i < n;i++) {
            int sum = seq[0] + seq[1] + seq[2];
            seq[0] = seq[1];
            seq[1] = seq[2];
            seq[2] = sum;
        }
        return seq[2];
    }
};