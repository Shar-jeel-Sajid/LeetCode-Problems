class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = x % 10, temp = x;
        while (temp /= 10)
            sum += (temp % 10);
        return x % sum ? -1 : sum;
    }
};