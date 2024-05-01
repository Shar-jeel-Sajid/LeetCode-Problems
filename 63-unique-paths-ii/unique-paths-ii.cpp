class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0])
            return 0;
        obstacleGrid[0][0] = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    continue;
                if (m - i - 1 && obstacleGrid[i+1][j] != 1)
                    obstacleGrid[i + 1][j] += obstacleGrid[i][j];
                if (n - 1 - j && obstacleGrid[i][j+1] != 1)
                    obstacleGrid[i][j + 1] += obstacleGrid[i][j];
            }
        }
        return obstacleGrid[m - 1][n - 1] * (-1);
    }
};