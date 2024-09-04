struct pair_hash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& pair) const {
        return hash<T1>()(pair.first) ^ hash<T2>()(pair.second);
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int result = -INT_MAX;

        // 使用unordered_set來記錄障礙物
        unordered_set<pair<int, int>, pair_hash> obs;
        for(auto &obstacle : obstacles){
            obs.insert({obstacle[0], obstacle[1]});
        }

        // 定義方向向量：北、東、南、西
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0; // 初始方向為北
        int x = 0, y = 0;
        
        for(auto &command : commands){
            // 轉向左 (-2)
            if(command == -2){
                direction = (direction + 3) % 4; // 轉向左等同於減1，再取模以防止負數
            }
            // 轉向右 (-1)
            else if(command == -1){
                direction = (direction + 1) % 4; // 轉向右等同於加1
            }
            // 向前移動
            else{
                for(int i = 0; i < command; i++){
                    int nx = x + directions[direction].first;
                    int ny = y + directions[direction].second;
                    // 如果下一步是障礙物，則停止移動
                    if(obs.count({nx, ny})) break;
                    // 更新位置
                    x = nx;
                    y = ny;
                }
            }

            // 計算距離的平方並更新結果
            result = max(result, x * x + y * y);
        }

        return result;
    }
};
