class Solution {
public:
    int maximumLength(vector<int>& nums) {
        if (nums.empty())
            return 0;
        map<int, int> freq;
        for (int& i : nums)
            freq[i]++;
        int ones = freq[1];
        if (ones % 2 == 0)
            ones--;
        freq.erase(1);
        auto iter = freq.begin();
        int count = 1,max = 0;
        long prev = iter->first;
        freq[prev]--;
        while (iter != freq.end()) {
            if (freq[prev] > 0 && prev * prev < INT_MAX &&
                freq.find(prev * prev) != freq.end()) {
                count += 2;
                freq[prev]--;
                prev *= prev;
                freq[prev]--;
                continue;
            }
            if (max < count)
                max = count;
            count = 1;
            prev = (++iter)->first;
            freq[prev]--;
        }
        return max > ones ? max : ones;
    }
};