class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        if(n == 0) return 0;

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            int cur_w = 0, cur_h = 0;
            int j = 1; // books counter
            while(j <= i){
                // update the current width and height
                cur_w += books[i-j][0];
                if(cur_w > shelfWidth) break;
                cur_h = max(cur_h, books[i-j][1]);

                // udpate the dp table
                dp[i] = min(dp[i], dp[i-j] + cur_h);

                // the next round
                j++;
            }
        }

        return dp[n];
    }
};