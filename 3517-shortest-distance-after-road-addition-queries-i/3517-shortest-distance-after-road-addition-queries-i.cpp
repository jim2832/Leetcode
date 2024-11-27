class Solution{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries){
        unordered_map<int, vector<int>> graph; // 完整圖結構
        vector<int> result(queries.size(), 0);

        // 動態處理查詢
        for(int i=0; i<queries.size(); i++){
            int s = queries[i][0];
            int e = queries[i][1];
            graph[s].push_back(e); // 更新圖結構

            // 使用 BFS 計算最短步數
            queue<int> q;
            vector<bool> visited(n, false);
            q.push(0);
            visited[0] = true;
            int steps = 0;

            bool found = false;
            while(!q.empty()){
                int size = q.size();
                for(int j=0; j<size; j++){
                    int curr = q.front();
                    q.pop();

                    if(curr == n - 1){
                        found = true;
                        break;
                    }

                    // 遍歷當前節點的鄰居
                    if(graph.count(curr)){
                        for(int neighbor : graph[curr]){
                            if(!visited[neighbor]){
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }

                    // 如果沒有映射，嘗試直接向下一個節點前進
                    if(curr + 1 < n && !visited[curr + 1]){
                        visited[curr + 1] = true;
                        q.push(curr + 1);
                    }
                }

                if(found) break;
                steps++;
            }

            result[i] = found ? steps : -1; // 如果無法到達終點，返回 -1
        }

        return result;
    }
};
