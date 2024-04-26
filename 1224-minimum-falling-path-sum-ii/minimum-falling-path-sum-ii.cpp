class Solution {
public:
    void findTwoMin(vector<int>* arr, int& min, int& min2) {
        int n = arr->size();
        min = 0;
        min2 = 1;
        if ((*arr)[min] > (*arr)[min2])
            min2 = !(min = 1);
        for (int i = 2; i < n; i++) {
            if ((*arr)[i] < (*arr)[min]) {
                min2 = min;
                min = i;
            }
            else if ((*arr)[i] < (*arr)[min2])
                min2 = i;
        }
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int min, min2, n = grid.size();
        if (n == 1)
            return grid[0][0];
        for (int i = 1; i < n; i++) {
            findTwoMin(&grid[i - 1], min, min2);
            for(int j = 0;j < n;j++)
                if(j != min)
                    grid[i][j] += grid[i-1][min];
                else
                    grid[i][j] += grid[i-1][min2];
        }
        return *min_element(grid[n-1].begin(),grid[n-1].end());
    }
};