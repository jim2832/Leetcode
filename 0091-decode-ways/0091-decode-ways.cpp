class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0'){
            return 0;
        }

        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1; // one way for decode empty string
        dp[1] = 1; // one way for decode string of length 1

        // iteration
        for(int i=2; i<n+1; i++){
            // Convert the current one-digit and two-digit substrings to integers
            int one_digit = s[i-1] - '0';
            int two_digits = stoi(s.substr(i-2, 2));

            // udpate dp[i] by adding dp[i-1] if the one-digit substring is not 0
            if(one_digit != 0){
                dp[i] += dp[i-1];
            }

            // update dp[i] by adding dp[i-1] if the alphabat number is between 10 and 26
            if(two_digits >= 10 && two_digits <= 26){
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};