class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n= mat[0].size();
        vector<vector<int>> result(r, vector<int>(c, 0));
        vector<int> temp;

        if(r*c == m*n){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    temp.push_back(mat[i][j]);
                }
            }

            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    result[i][j] = temp[0];
                    temp.erase(temp.begin());
                }
            }

            return result;
        }

        return mat;
    }
};