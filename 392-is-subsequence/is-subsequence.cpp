class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(),n = t.length();
        if(m > n)
            return false;
        int j = 0;
        for(int i = 0;i < m;i++) {
            char c = s[i];
            for(;j < n;j++)
                if(c == t[j])
                    break;
            if(j == n)
                return false;
            else
                j++;
        }
        return true;
    }
};