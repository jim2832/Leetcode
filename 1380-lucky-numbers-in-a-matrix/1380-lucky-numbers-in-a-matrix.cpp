class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> row_min(row, INT_MAX), col_max(col, -INT_MAX);
        vector<int> result;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                row_min[i] = min(row_min[i], matrix[i][j]);
                col_max[j] = max(col_max[j], matrix[i][j]);
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] <= row_min[i] && matrix[i][j] >= col_max[j]){
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};