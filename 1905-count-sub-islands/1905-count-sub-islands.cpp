class Solution {
public:
    bool outofbound(int i, int j, int row, int col){
        return (i < 0) || (i > row-1) || (j < 0) || (j > col-1);
    }

    void DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &flag){
        int row = grid2.size(), col = grid2[0].size();

        if(outofbound(i, j, row, col) || grid2[i][j] == 0) return;
        if(grid1[i][j] == 0){
            flag = false;
            return;
        }
        grid2[i][j] = 0;

        DFS(grid1, grid2, i, j-1, flag);
        DFS(grid1, grid2, i, j+1, flag);
        DFS(grid1, grid2, i-1, j, flag);
        DFS(grid1, grid2, i+1, j, flag);
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size(), col = grid2[0].size();
        int sub_island = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid2[i][j]){
                    bool flag = true;
                    DFS(grid1, grid2, i, j, flag);
                    if(flag) sub_island++;
                }
            }
        }

        return sub_island;
    }
};