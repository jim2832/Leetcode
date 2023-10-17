class Solution{
public:
    // Function to transpose a matrix in-place
    void transpose(vector<vector<int>>& matrix){
        int row = matrix.size();

        for(int i=0; i<row; i++){
            for(int j=i+1; j<row; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // Function to reverse the columns of a matrix
    void reverseColumns(vector<vector<int>>& matrix){
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col/2; j++){
                swap(matrix[i][j], matrix[i][col-1-j]);
            }
        }
    }

    void rotate(vector<vector<int>>& matrix){
        transpose(matrix);
        reverseColumns(matrix);
    }
};