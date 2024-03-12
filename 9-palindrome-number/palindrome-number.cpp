class Solution {
public:
    int noOfPlaces (int n) {
        int places = 1;
        while(n/=10)
            places++;
        return places;
    }

    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int n = noOfPlaces(x), j = 0;
        if(n == 1)
            return true;
        n/=2;
        while(n--) {
            j = (j*10) + (x%10);
            x/=10;
        }
        if(noOfPlaces(x) != noOfPlaces(j))
            x/=10;
        return x == j;
    }
};