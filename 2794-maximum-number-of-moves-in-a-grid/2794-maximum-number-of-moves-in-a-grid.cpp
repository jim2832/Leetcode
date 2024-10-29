class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxi = INT_MIN;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int j=col-2; j>=0; j--){
            for(int i=0; i<row; i++){
                // left top
                if(i > 0 && grid[i-1][j+1] > grid[i][j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j+1] + 1);
                }
                // left
                if(grid[i][j+1] > grid[i][j]){
                    dp[i][j] = max(dp[i][j], dp[i][j+1] + 1);
                }
                // left down
                if(i < row-1 && grid[i+1][j+1] > grid[i][j]){
                    dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
                }
            }
        }

        for(int i=0; i<row; i++){
            maxi = max(maxi, dp[i][0]);
        }

        return maxi;
    }
};