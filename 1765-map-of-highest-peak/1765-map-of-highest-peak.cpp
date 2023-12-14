// 對每個 water 的來源點做BFS

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> result(row, vector<int>(col, INT_MAX));
        queue<pair<int, int>> q; // BFS queue

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isWater[i][j] == 1){ // water grid
                    q.push({i,j});
                    result[i][j] = 0;
                }
            }
        }

        // BFS
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int new_x = x + dirs[i].first;
                int new_y = y + dirs[i].second;

                if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && result[new_x][new_y] > result[x][y] + 1){
                    result[new_x][new_y] = result[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }

        return result;
    }
};