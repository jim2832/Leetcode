class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 0;

        vector<int> dp(n, 1), prev(n, -1);
        vector<int> result;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[maxi]){
                maxi = i;
            }
        }

        for(int i = maxi; i>=0; i = prev[i]){
            result.push_back(nums[i]);
        }

        return result;
    }
};