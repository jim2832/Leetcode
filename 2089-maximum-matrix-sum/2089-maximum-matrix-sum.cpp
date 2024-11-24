class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        long long sum = 0;
        int mini = INT_MAX, count = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                sum += abs(matrix[i][j]);
                mini = min(mini, abs(matrix[i][j]));
                if(matrix[i][j] < 0) count++;
            }
        }

        return count % 2 ? sum - 2 * mini : sum;
    }
};