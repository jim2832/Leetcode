class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;

        for(int i=0; i<=rowIndex; i++){
            vector<int> temp(i+1, 1);
            dp.push_back(temp);
            for(int j=1; j<i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }

        return dp[rowIndex];
    }
};