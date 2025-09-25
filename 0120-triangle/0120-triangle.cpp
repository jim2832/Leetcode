class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = triangle[0];
        int mini = INT_MAX;

        for(int i = 1; i < n; i++){
            int m = triangle[i].size();
            vector<int> temp(m);
            dp[i] = temp;
            for(int j = 0; j < m; j++){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j == m - 1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }

        for(int i = 0; i < dp[n-1].size(); i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};