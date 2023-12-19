class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();

        vector<vector<int>> result(row, vector<int>(col, 0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // calculate the average
                int sum = 0;
                int count = 0;
                for(int ii=max(0,i-1); ii<min(row,i+2); ii++){
                    for(int jj=max(0,j-1); jj<min(col,j+2); jj++){
                        sum += img[ii][jj];
                        count++;
                    }
                }
                result[i][j] = sum / count;
            }
        }

        return result;
    }
};