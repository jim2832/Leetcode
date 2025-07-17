class Solution {
public:
    bool out(int i, int j, int row, int col){
        return i < 0 || i >= row || j < 0 || j >= col;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int minute = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(!fresh) return 0;
        if(q.empty()) return -1;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto &[dx, dy] : dirs){
                    int newX = x + dx;
                    int newY = y + dy;
                    if(!out(newX, newY, row, col) && grid[newX][newY] == 1){
                        grid[newX][newY] = 2;
                        fresh--;
                        q.push({newX, newY});
                    }
                }
            }
            minute++;
        }

        return fresh ? -1 : minute - 1;
    }
};