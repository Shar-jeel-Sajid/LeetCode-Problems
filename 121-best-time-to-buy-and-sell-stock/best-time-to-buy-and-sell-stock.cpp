class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> profits;
        int buy = prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                profits.push_back(sell - buy);
                buy = prices[i];
                sell = 0;
                continue;
            }
            if (prices[i] > sell) {
                sell = prices[i];
            }
        }
        profits.push_back(sell - buy);
        int max = *max_element(profits.begin(), profits.end());
        return max > 0 ? max : 0;
    }
};