class Solution {
public:
    bool outofbound(int i, int j, int row, int col){
        return (i < 0) || (i > row-1) || (j < 0) || (j > col-1);
    }

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited){
        int row = grid.size();
        int col = grid[0].size();

        if(outofbound(i, j, row, col) || visited[i][j] || grid[i][j] == 0){
            return 0;
        }
        visited[i][j] = true;

        return grid[i][j] +
                DFS(grid, i+1, j, visited) +
                DFS(grid, i-1, j, visited) +
                DFS(grid, i, j+1, visited) +
                DFS(grid, i, j-1, visited);
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> visited(row, vector(col, false));

        int max_fish = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] && !visited[i][j]){
                    max_fish = max(max_fish, DFS(grid, i, j, visited));
                }
            }
        }

        return max_fish;
    }
};