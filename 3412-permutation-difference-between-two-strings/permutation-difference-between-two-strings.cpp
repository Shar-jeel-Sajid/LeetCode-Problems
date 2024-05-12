class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int sum = 0,n = s.length();
        int freq[26];
        for(int i = 0;i < n;i++)
            freq[s[i]-'a'] = i;
        for(int i = 0;i < n;i++)
            sum += abs(i-freq[t[i]-'a']);
            // cout << i << " " << freq[t[i]-'a'];
        return sum;    
    }
};