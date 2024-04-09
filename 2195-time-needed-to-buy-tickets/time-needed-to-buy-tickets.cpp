class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, sum = 0;
        for (int i = 0; i < tickets.size(); i++) {
            sum += tickets[i];
            ans += min(tickets[k], tickets[i]);
            if (k < i && tickets[i] >= tickets[k])
                ans--;
        }
        return ans;
    }
};