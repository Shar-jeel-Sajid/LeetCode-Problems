class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangles) {
        int n = triangles.size();
        for(int i = n-2;i>=0;i--)
            for(int j = 0;j < triangles[i].size();j++)
                triangles[i][j] += min(triangles[i+1][j],triangles[i+1][j+1]);
        return triangles[0][0];
    }
};