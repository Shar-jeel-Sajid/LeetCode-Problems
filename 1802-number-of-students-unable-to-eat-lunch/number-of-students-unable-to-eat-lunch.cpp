class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for (int& i : students)
            count[i]++;
        for (int& i : sandwiches) {
            if (--count[i] < 0)
                return count[!(i)];
        }
        return count[0] + count[1];
    }
};