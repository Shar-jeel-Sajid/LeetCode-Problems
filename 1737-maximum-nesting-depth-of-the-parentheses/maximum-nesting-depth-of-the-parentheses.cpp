class Solution {
public:
    int maxDepth(string s) {
        int max = 0, depth = 0;
        for (char& c : s) {
            if (c == '(')
                depth++;
            if (c == ')')
                depth--;
            if (max < depth)
                max = depth;
        }
        return max;
    }
};