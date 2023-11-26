/*

1 1 0
1 0 1
->
1 1 0
1 0 1

*/

bool compare(const int num1, const int num2){
    return num1 >= num2;
}

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_area = 0;

        for(int i=1; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i-1][j] >= 1 && matrix[i][j]){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }

        for(int i=0; i<row; i++){
            // sorting
            sort(matrix[i].begin(), matrix[i].end());

            // Iterate through the sorted heights
            for(int j=0; j<col; j++){
                int h = matrix[i][j];
                int w = col - j;
                max_area = max(max_area, h * w);
            }
        }

        return max_area;
    }
};