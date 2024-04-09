class Solution {
public:
    void findLetters(vector<char>& arr, int digit) {
        int i = 3;
        char alpha;
        if (digit < 6)
            alpha = 'a' + (digit * 3);
        if (digit == 5)
            i = 4;
        if (digit == 6)
            alpha = 't';
        if (digit == 7) {
            alpha = 'w';
            i = 4;
        }
        for (int j = 0; j < i; j++)
            arr.push_back(alpha++);
    }

    void insertString(queue<string>& comb, int digit) {
        int n = comb.size();
        vector<char> letters;
        findLetters(letters, digit - 50);
        for (int i = 0; i < n; i++) {
            string tmp = comb.front();
            comb.pop();
            for (int j = 0; j < letters.size(); j++) {
                tmp.push_back(letters[j]);
                comb.push(tmp);
                tmp.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        queue<string> comb;
        comb.push("");
        vector<char> tmp;
        for (char& c : digits)
            insertString(comb, c);
        vector<string> ans;
        int n = comb.size();
        for (int i = 0; i < n && n != 1; i++) {
            ans.push_back(comb.front());
            comb.pop();
        }
        return ans;
    }
};