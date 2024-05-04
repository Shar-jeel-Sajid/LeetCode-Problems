class Solution {
public:
    int isValid(int a, int b) {
        if(b == 0) {
            if(a == 1 || a == 2)
                return 2;
            return 0;
        } 
        if(b < 7) {
            if(a==1 || a == 2)
                return 3;
            return 1;
        }
        if(a == 1)
            return 3;
        return 1;
    }

    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int n = s.length();
        if(n == 1)
            return 1;
        vector<int> count(n,0);
        count[0] = 1;
        {
            int tmp = isValid(s[0]-48,s[1]-48);
            switch(tmp) {
                case 0:
                    return 0;
                case 1:
                    count[1] = 1;
                    break;
                case 2:
                    count[1] = 1;
                    break;
                case 3:
                    count[1] = 2;
                    break;
            }
        }
        for(int i = 2;i < n;i++) {
            int tmp = isValid(s[i-1]-48,s[i]-48);
            switch(tmp) {
                case 0:
                    return 0;
                case 1:
                    count[i] = count[i-1];
                    break;
                case 2:
                    count[i] = count[i-2];
                    break;
                case 3:
                    count[i] = count[i-1] + count[i-2];
            }

        }
        return count[n-1];
    }
};