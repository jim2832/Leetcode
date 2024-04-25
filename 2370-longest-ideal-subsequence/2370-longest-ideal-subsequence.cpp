class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int result = 0;
        vector<int> dp(200);

        for(auto &c : s){
            for(int i=c-k; i<=c+k; i++){
                dp[c] = max(dp[c], dp[i]);
            }
            dp[c]++;
            result = max(result, dp[c]);
        }

        return result;
    }
};