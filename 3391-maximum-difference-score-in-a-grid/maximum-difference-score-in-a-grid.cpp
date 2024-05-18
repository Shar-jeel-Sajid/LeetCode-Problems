class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), maxScore = INT_MIN;
        vector<vector<int>> score(n, vector<int>(m, INT_MIN));
        score[n-1][m-1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int localMax = INT_MIN;
                for (int k = j + 1; k < m; k++)
                    localMax =
                        max(localMax, score[i][k] + grid[i][k] - grid[i][j]);
                for (int k = i + 1; k < n; k++)
                    localMax =
                        max(localMax, score[k][j] + grid[k][j] - grid[i][j]);
                score[i][j] = max(0,localMax);
                maxScore = max(maxScore,localMax);
            }
        }
        return maxScore;
    }
};