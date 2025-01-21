class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = 0, bottomSum = 0, result = LLONG_MAX;

        for(int i=0; i<n; i++){
            topSum += grid[0][i];
        }

        for(int i=0; i<n; i++){
            // topSum 和 bottomSum 分別代表了玩家 2 在兩個部分的可選範圍。
            // max(topSum, bottomSum)：模擬了玩家 2 的最佳行動，始終選擇較大值。
            // min(result, ...)：確保第一位玩家能選擇最佳行動，最小化玩家 2 的最大收益。
            topSum -= grid[0][i];
            result = min(result, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }

        return result;
    }
};