class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (int i = 0; i < s.length(); i++) {
            if (!ans.length()) {
                ans.push_back(s[i]);
                continue;
            }
            char c = ans.back();
            if (islower(c) && toupper(c) == s[i] ||
                isupper(c) && tolower(c) == s[i])
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};