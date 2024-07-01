class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size() - 1;
        if(n < 2)
            return 0;
        for(int i = n;i >= 2;i--){
            arr[i] += arr[i-1] +arr[i-2];
            if(arr[i]%2 && arr[i-1]%2)
                return 1;
        }
        return 0;
    }
};