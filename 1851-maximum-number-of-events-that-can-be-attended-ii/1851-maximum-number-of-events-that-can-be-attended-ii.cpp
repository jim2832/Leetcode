class Solution{
public:
    int binarySearch(vector<vector<int>>& events, int currentStart){
        int lower = 0, upper = events.size() - 1;
        int result = -1;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            if(events[mid][1] < currentStart){
                result = mid;
                lower = mid + 1;
            }
            else{
                upper = mid - 1;
            }
        }

        return result;
    }

    int maxValue(vector<vector<int>>& events, int k){
        sort(events.begin(), events.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for(int i = 1; i <= n; i++){
            int prev = binarySearch(events, events[i-1][0]);
            for(int j = 1; j <= k; j++){
                dp[i][j] = max(dp[i-1][j], dp[prev+1][j-1] + events[i-1][2]);
            }
        }

        return dp[n][k];
    }
};