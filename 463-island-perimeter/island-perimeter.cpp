class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
            grid[i].push_back(0);
        grid.push_back(vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]) {
                    sum += 2;
                    if (i - 1 >= 0 && grid[i - 1][j])
                        sum--;
                    if (j - 1 >= 0 && grid[i][j - 1])
                        sum--;
                } else {
                    if (i - 1 >= 0 && grid[i - 1][j])
                        sum++;
                    if (j - 1 >= 0 && grid[i][j - 1])
                        sum++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) 
                cout << grid[i][j];
            cout << endl;
        }
        return sum;
    }
};