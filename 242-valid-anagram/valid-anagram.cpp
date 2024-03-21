class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char,int> freq;
        for(char &c:s)
            freq[c]++;
        for(char &c : t) {
            if(freq.find(c) == freq.end())
                return false;
            if(freq[c]-- < 0)
                return false;
        }
        for(auto i:freq)
            if(i.second > 0)
                return false;
        return true;
    }
};