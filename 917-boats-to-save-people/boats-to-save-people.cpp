class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0;
        sort(people.begin(), people.end(), greater<int>());
        int l = 0, r = people.size() - 1;
        while (l <= r) {
            count++;
            if (l!=r && people[l] + people[r] <= limit)
                r--;
            l++;
        }
        return count;
    }
};