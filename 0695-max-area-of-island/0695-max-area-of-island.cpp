class Solution {
public:
    int DFS(int i, int j, vector<vector<int>>& grid){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        if(grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        return 1 + DFS(i+1, j, grid)
                 + DFS(i-1, j, grid)
                 + DFS(i, j+1, grid)
                 + DFS(i, j-1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int maxi = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi, DFS(i, j, grid));
                }
            }
        }

        return maxi;
    }
};