class Solution {
public:
    int numberOfChild(int n, int k) {
        int i = 0, step = 1;
        while (k-- > 0) {
            if (n - 1 == i)
                step = -1;
            if (i == 0)
                step = 1;
            i += step;
        }
        return i;
    }
};