class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_map<int, pair<int, int>> hash;
        vector<int> rows(row, col), cols(col, row);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                hash[mat[i][j]] = {i, j};
            }
        }

        for(int i=0; i<arr.size(); i++){
            int r = hash[arr[i]].first;
            int c = hash[arr[i]].second;
            if(--rows[r] == 0 || --cols[c] == 0){
                return i;
            }
        }

        return 0;
    }
};