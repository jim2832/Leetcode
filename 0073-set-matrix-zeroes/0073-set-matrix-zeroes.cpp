class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        unordered_set<int> r, c;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(r.count(i) || c.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};