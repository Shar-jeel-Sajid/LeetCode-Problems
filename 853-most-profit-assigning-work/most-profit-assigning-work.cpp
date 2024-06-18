// Comparator for priority queue based on key (min-heap by default)
struct Compare {
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs) const {
        return lhs.first > rhs.first; 
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum = 0;
        sort(worker.begin(),worker.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> q;
        int n = profit.size(),m = worker.size();
        for(int i = 0;i < n;i++) {
            q.push(pair<int,int>(difficulty[i],profit[i]));
        }
        for(int i = 0;i < m;i++){
            int maxi = 0;
            while(true) {
                if(q.empty() || q.top().first > worker[i]) {
                    sum += maxi;
                    q.push(pair<int,int>(worker[i],maxi));
                    break;
                }
                maxi = max(q.top().second,maxi);
                q.pop();
            }
        }
        return sum;
    }
};