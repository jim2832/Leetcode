/*

[0,0,0]    [0,  0, 0]
[0,1,0] -> [0, -1, 0]
[1,1,1]    [-1,-1,-1]

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q; // BFS queue
        vector<vector<int>> result(row, vector<int>(col, -1));

        // set the 0 field into 0 in the new matrix and add them into queue
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 0){
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

            // four directions
            for(int i=0; i<4; i++){
                int new_x = x + dirs[i].first;
                int new_y = y + dirs[i].second;
                if(new_x>=0 && new_x<row && new_y>=0 && new_y<col && result[new_x][new_y] == -1){
                    q.push({new_x, new_y});
                    result[new_x][new_y] = result[x][y] + 1;
                }
            }
        }

        return result;
    }
};