/*

arr = [1,15,7,9,2,5,10]
dp = [0,15,15,15,9,10,10,10]

*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int i=1; i<=n; i++){
            int maxi = -INT_MAX; // find the maximal number within the range
            for(int j=1; j<=k && i-j>=0; j++){
                // udpate the maximal number within the range
                maxi = max(maxi, arr[i-j]);
                // update the maximum sum for the current index by considering the partitioning
                dp[i] = max(dp[i], dp[i-j] + maxi * j);
            }
            // cout << "i=" << i << ": " << maxi << " " << dp[i] << endl;
        }

        return dp[n];
    }
};