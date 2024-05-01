class Solution {
public:
    string reversePrefix(string word, char ch) {
        int j = word.length(), i = 0;
        for (; i < j; i++)
            if (word[i] == ch)
                break;
        if (i == j)
            return word;
        j = 0;
        while (i > j) {
            ch = word[j];
            word[j++] = word[i];
            word[i--] = ch;
        }
        return word;
    }
};