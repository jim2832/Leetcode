class Solution {
public:
    int find_max(vector<vector<int>>& grid, int row, int col){
        int n = grid.size();
        int maxi = 0;
        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                maxi = max(maxi, grid[i][j]);               
            }
        }

        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2));

        for(int i=0; i<=n-3; i++){
            for(int j=0; j<=n-3; j++){
                result[i][j] = find_max(grid, i, j);
            }
        }

        return result;
    }
};