bool compareInterval(vector<int>& i1, vector<int>& i2) {
    return (i1[0] < i2[0]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end(), compareInterval);
        merged.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int n = merged.size() - 1;
            if (merged[n][1] >= intervals[i][0]) {
                if(merged[n][1] < intervals[i][1])
                    merged[n][1] = intervals[i][1];
            }
            else
                merged.push_back(intervals[i]);
        }
        return merged;
    }
};