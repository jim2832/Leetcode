class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int last_day = days.back();
        vector<int> dp(last_day+1);
        set<int> s(days.begin(), days.end());

        for(int i=1; i<=last_day; i++){
            if(!s.count(i)){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = min({dp[i-1] + costs[0], 
                            dp[max(i-7, 0)] + costs[1],
                            dp[max(i-30, 0)] + costs[2]});
            }
        }

        return dp[last_day];
    }
};