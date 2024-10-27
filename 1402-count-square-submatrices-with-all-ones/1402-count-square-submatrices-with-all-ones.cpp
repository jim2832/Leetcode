class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));
        int result = 0;

        // init the cols
        for(int i=0; i<row; i++){
            dp[i][0] = matrix[i][0];
            result += matrix[i][0];
        }

        // init the rows
        for(int j=1; j<col; j++){
            dp[0][j] = matrix[0][j];
            result += matrix[0][j];
        }

        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(matrix[i][j]){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
                result += dp[i][j];
            }
        }

        return result;
    }
};