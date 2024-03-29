class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int row = text1.size();
        int col = text2.size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, 0));

        for(int i=0; i<=row; i++){
            for(int j=0; j<=col; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else if(text1[i-1] != text2[j-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[row][col];
    }
};