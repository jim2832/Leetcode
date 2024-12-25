class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] != -1) { // 將 manager 與員工建立圖結構
                graph[manager[i]].push_back(i);
            }
        }

        queue<pair<int, int>> q; // pair<當前節點, 累積時間>
        q.push({headID, 0});
        int maxTime = 0;

        while (!q.empty()) {
            auto [current, time] = q.front();
            q.pop();

            // 更新最大時間
            maxTime = max(maxTime, time);

            // 遍歷當前節點的所有下屬
            for (int subordinate : graph[current]) {
                q.push({subordinate, time + informTime[current]});
            }
        }

        return maxTime;
    }
};
