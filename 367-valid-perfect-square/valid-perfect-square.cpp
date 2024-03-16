class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 4)
            return num == 1;
        int left = 0,right = num;
        while(left < right-1){
            long n = (left+right)/2;
            if(n*n == num)
                return true;
            if(n*n < num)
                left = n;
            if(n*n > num)
                right = n;
        }
        return false;
    }
};