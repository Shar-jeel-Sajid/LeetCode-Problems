class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int sum = 0,i = seats.size();
        while(i--)
            sum += abs(seats[i]-students[i]);
        return sum;
    }
};