class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for(int i = 0;i < n;i++){
            if(grid[i][0])
                continue;
            for(int j = 0;j < m;j++)
                grid[i][j] = !grid[i][j];
        }
        int sum = 0,carry = 0;
        for(int j = m - 1;j >= 0;j--){
            int ones = 0;
            for(int i = 0;i < n;i++)
                ones += grid[i][j];
            ones = max(ones,n - ones);
            ones *= pow(2,m - j - 1);
            sum += ones; 
        }
        return sum;
    }
};