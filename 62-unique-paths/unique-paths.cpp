class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        grid[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (m - i - 1)
                    grid[i + 1][j] += grid[i][j];
                if (n - 1 - j)
                    grid[i][j + 1] += grid[i][j];
            }
        }
        return grid[m - 1][n - 1];
    }
};