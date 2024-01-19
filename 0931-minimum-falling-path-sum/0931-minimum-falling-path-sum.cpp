class Solution {
public:
    bool is_valid(int i, int j, int row, int col){
        return i>=0 && i<row && j>=0 && j<col;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                int left = INT_MAX, mid = INT_MAX, right = INT_MAX;
                // left
                if(is_valid(i-1, j-1, row, col)){
                    left = matrix[i-1][j-1];
                }
                // mid
                if(is_valid(i-1, j, row, col)){
                    mid = matrix[i-1][j];
                }
                // right
                if(is_valid(i-1, j+1, row, col)){
                    right = matrix[i-1][j+1];
                }
                int mini = min(left, min(mid, right));
                // cout << mini << " ";
                matrix[i][j] += mini;
            }
        }

        int mini = INT_MAX;
        for(int j=0; j<col; j++){
            mini = min(mini, matrix[matrix.size()-1][j]);
        }

        return mini;
    }
};