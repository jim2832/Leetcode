class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        long long sum = 0;
        int min = INT_MAX; // absolute minimum number
        int neg_num = 0; // the number of negative

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                sum += abs(matrix[i][j]);

                // record the number of negative number
                if(matrix[i][j] < 0){
                    neg_num++;
                }

                // update the minimim number
                if(min > abs(matrix[i][j])){
                    min = abs(matrix[i][j]);
                }
            }
        }

        if(neg_num % 2 == 1){
            return sum - 2*min;
        }

        return sum;
    }
};