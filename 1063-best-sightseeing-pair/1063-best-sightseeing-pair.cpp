class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = INT_MIN;
        int n = values.size();
        vector<int> dp(n);
        dp[0] = values[0];

        for(int i=1; i<n; i++){
            maxi = max(maxi, dp[i-1] + values[i] - i);
            dp[i] = max(dp[i-1], values[i] + i);
        }

        return maxi;
    }
};