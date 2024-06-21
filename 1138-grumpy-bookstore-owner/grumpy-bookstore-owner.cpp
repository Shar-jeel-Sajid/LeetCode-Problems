class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0,total = 0,n = customers.size();
        for(int i = 0;i < n;i++) {
            total += customers[i];
            sum += (customers[i] *= grumpy[i]);
            cout << customers[i] << " ";
        }
        int cur = 0;
        for(int i = 0;i < minutes;i++)
            cur += customers[i];
        int max = cur;
        for(int i = 0;i < n - minutes;i++){
            cur -= customers[i];
            cur += customers[i+minutes];
            if(max < cur)
                max = cur;
        }
        return total-sum+max;
    }
};