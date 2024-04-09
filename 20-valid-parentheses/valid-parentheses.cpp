class Solution {
public:
    bool isValid(string s) {
        stack<char> cont;
        for (char& c : s) {
            if (cont.empty()) {
                cont.push(c);
                continue;
            }
            if ((c == ')' && cont.top() == '(') ||
                (c == '}' && cont.top() == '{') ||
                (c == ']' && cont.top() == '['))
                cont.pop();
            else
                cont.push(c);
        }
        return cont.empty();
    }
};