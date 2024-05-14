class Solution {
public:
    int DFS(vector<vector<int>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();

        // out of bound or already visited or 0 grid
        if(i<0 || j<0 || i>row-1 || j>col-1 || !grid[i][j]) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;

        int res = 0;
        res = max(res, DFS(grid, i+1, j));
        res = max(res, DFS(grid, i-1, j));
        res = max(res, DFS(grid, i, j+1));
        res = max(res, DFS(grid, i, j-1));

        grid[i][j] = temp;

        return grid[i][j] + res;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int result = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]){
                    result = max(result, DFS(grid, i, j));
                }
            }
        }

        return result;
    }
};