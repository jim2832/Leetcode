class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[200001] = {};

        for(int i=n-1; i>=0; i--){
            int point = questions[i][0];
            int brainpower = questions[i][1];
            dp[i] = max(dp[i+1], dp[i + brainpower + 1] + point);
        }

        return dp[0];
    }
};