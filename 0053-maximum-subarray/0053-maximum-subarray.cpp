class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};