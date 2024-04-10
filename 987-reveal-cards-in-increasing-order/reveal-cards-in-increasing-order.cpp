class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        if (deck.size() < 3)
            return deck;
        vector<int> ans;
        int n = (deck.size() + 1) / 2;
        vector<int> tmp(deck.begin() + n, deck.end());
        tmp = deckRevealedIncreasing(tmp);
        if(deck.size()%2) {
            tmp.insert(tmp.begin(),tmp.back());
            tmp.pop_back();
        }
        for (int i = 0; i < n; i++) {
            ans.push_back(deck[i]);
            if (i < tmp.size())
                ans.push_back(tmp[i]);
        }
        return ans;
    }
};