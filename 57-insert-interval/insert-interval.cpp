class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() < 1) {
            res.push_back(newInterval);
            return res;
        }
        int start = newInterval[0], index = 0, end = newInterval[1];
        if (newInterval[0] < intervals[0][0]) {
            res.push_back(newInterval);
        }
        while (index < intervals.size() && intervals[index][0] <= start) {
            res.push_back(intervals[index]);
            index++;
        }
        while (1) {
            int n = res.size() - 1;
            if (res[n][1] >= start) {
                if (res[n][1] < end)
                    res[n][1] = end;
            }
            if (res[n][1] < start) {
                res.push_back(vector<int>({start, end}));
                cout << 1;
            }
            if (index >= intervals.size())
                break;
            start = intervals[index][0];
            end = intervals[index][1];
            index++;
        }
        return res;
    }
};