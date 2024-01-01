class Solution {
public:
    // Helper function to check if a given position (i, j) is within the grid boundaries
    bool is_valid(int i, int j, int row, int col){
        return i>=0 && i<row && j>=0 && j<col;
    }

    // Depth-First Search function to explore and mark connected components (islands)
    bool DFS(int i, int j, int row, int col, vector<vector<int>>& grid){
        // Check if the current position is outside the grid boundaries
        if(!is_valid(i, j, row, col)){
            return false;
        }
        // Check if the current position is part of an island
        if(grid[i][j] == 1){
            return true;
        }
        // Mark the current position as visited
        grid[i][j] = 1; // visited
        
        // Recursively explore in all four directions
        bool up = DFS(i-1, j, row, col, grid);
        bool down = DFS(i+1, j, row, col, grid);
        bool left = DFS(i, j-1, row, col, grid);
        bool right = DFS(i, j+1, row, col, grid);

        // If all four directions return true, then the current position forms a closed island
        return up && down && left && right;
    }

    // Main function to count the number of closed islands in the grid
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int count = 0;
        // Iterate through each cell in the grid
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // Check if the current cell is part of an unmarked island and explore it using DFS
                if(grid[i][j] == 0 && DFS(i, j, row, col, grid)){
                    count++;
                }
            }
        }

        // Return the count of closed islands
        return count;
    }
};
