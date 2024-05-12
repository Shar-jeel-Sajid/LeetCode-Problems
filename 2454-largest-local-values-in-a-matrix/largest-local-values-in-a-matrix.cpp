class Solution {
public:
    int findMax(vector<vector<int>>& grid, int i, int j) {
        int tmp[3] = {
            *max_element(grid[i].begin() + j, grid[i].begin() + j + 3),
            *max_element(grid[i + 1].begin() + j, grid[i + 1].begin() + j + 3),
            *max_element(grid[i + 2].begin() + j, grid[i + 2].begin() + j + 3)};
        return max(tmp[0], max(tmp[1], tmp[2]));
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2,
                                vector<int>(n-2, 0));
        for(int i = 0;i < n-2;i++){
            for(int j = 0;j < n-2;j++){
                ans[i][j] = findMax(grid,i,j);
            }
        }
        return ans;
    }
};