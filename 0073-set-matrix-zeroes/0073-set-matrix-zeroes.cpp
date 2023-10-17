class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        unordered_map<int, int> r;
        unordered_map<int, int> c;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    r[i] = 0;
                    c[j] = 0;
                }
            }
        }

        // for(auto iter=hash.begin(); iter!=hash.end(); iter++){
        //     cout << iter->first << " " << iter->second << endl;
        // }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(r.find(i) != r.end() || c.find(j) != c.end()){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};