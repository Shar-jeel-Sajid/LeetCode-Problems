class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return vector<vector<int>>();
        vector<vector<int>> answer;
        answer.push_back({1});
        if(numRows == 1)
            return answer;
        answer.push_back({1,1});
        if(numRows == 2)
            return answer;
        for(int i = 3;i <= numRows;i++){
            int j = 0;
            vector<int> current;
            current.push_back(1);
            while(j+1 < answer[i-2].size()){
                current.push_back(answer[i-2][j++]+answer[i-2][j]);
            }
            current.push_back(1);
            answer.push_back(current);
        }    
        return answer;
    }
};