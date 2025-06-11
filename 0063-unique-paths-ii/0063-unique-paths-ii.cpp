class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> DP(row, vector<int>(col, 0));

        bool rock = false;
        for(int i = 0; i < row; i++){
            if(obstacleGrid[i][0] == 1 || rock){
                DP[i][0] = 0;
                rock = true;
            }
            else{
                DP[i][0] = 1;
            }
        }

        rock = false;
        for(int j = 0; j < col; j++){
            if(obstacleGrid[0][j] == 1 || rock){
                DP[0][j] = 0;
                rock = true;
            }
            else{
                DP[0][j] = 1;
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(obstacleGrid[i][j] == 1){
                    DP[i][j] = 0;
                }
                else{
                    DP[i][j] = DP[i-1][j] + DP[i][j-1];
                }
            }
        }

        return DP[row-1][col-1];
    }
};