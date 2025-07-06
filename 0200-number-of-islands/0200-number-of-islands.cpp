class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';

        DFS(i + 1, j, grid);
        DFS(i, j + 1, grid);
        DFS(i - 1, j, grid);
        DFS(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row = grid.size(), col = grid[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '1'){
                    DFS(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};