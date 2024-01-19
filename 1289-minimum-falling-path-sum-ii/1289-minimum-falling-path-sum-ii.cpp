class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                int mini = INT_MAX;
                for(int k=0; k<col; k++){
                    if(j == k){
                        continue;
                    }
                    mini = min(mini, grid[i-1][k]);
                }
                grid[i][j] += mini;
            }
        }

        int result = INT_MAX;
        for(int j=0; j<col; j++){
            result = min(result, grid[grid.size()-1][j]);
        }

        return result;
    }
};

/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                int mini = INT_MAX;
                for(int k=0; k<col; k++){
                    if(j == k){
                        continue;
                    }
                    mini = min(mini, grid[i-1][k]);
                }
                grid[i][j] += mini;
            }
        }

        int result = INT_MAX;
        for(int j=0; j<col; j++){
            result = min(result, grid[grid.size()-1][j]);
        }

        return result;
    }
};
*/