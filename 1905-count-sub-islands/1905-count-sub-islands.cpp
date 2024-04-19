class Solution {
public:
    bool outofbound(int i, int j, int row, int col){
        return (i < 0) || (i > row-1) || (j < 0) || (j > col-1);
    }

    void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, vector<vector<bool>> &visited, bool &flag){
        int row = grid2.size(), col = grid2[0].size();

        if(outofbound(i, j, row, col) || visited[i][j] || grid2[i][j] == 0) return;
        if(grid1[i][j] == 0){
            flag = false;
            return;
        }
        visited[i][j] = true;

        DFS(grid1, grid2, i+1, j, visited, flag);
        DFS(grid1, grid2, i-1, j, visited, flag);
        DFS(grid1, grid2, i, j+1, visited, flag);
        DFS(grid1, grid2, i, j-1, visited, flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size(), col = grid2[0].size();
        int sub_island = 0;

        vector<vector<bool>> visited(row, vector(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j] && !visited[i][j]){
                    bool flag = true;
                    DFS(grid1, grid2, i, j, visited, flag);
                    if(flag) sub_island++;
                }
            }
        }

        return sub_island;
    }
};