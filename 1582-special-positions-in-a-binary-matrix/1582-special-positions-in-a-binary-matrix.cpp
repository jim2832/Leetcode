class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, int> row_contain_one;
        unordered_map<int, int> col_contain_one;
        int count = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    row_contain_one[i]++;
                    col_contain_one[j]++;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    if(row_contain_one[i] == 1 && col_contain_one[j] == 1){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};