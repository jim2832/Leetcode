class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n+1, 0);

        // rob the first house + the second last two house
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i=2; i<n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int rob1 = dp[n-1];

        // rob the second house + the last one house
        dp[1] = 0;
        dp[2] = nums[1];
        for(int i=3; i<=n; i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        int rob2 = dp[n];

        return max(rob1, rob2);
    }
};