/*
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        unordered_map<int, int> onesRow, onesCol, zerosRow, zerosCol;
        vector<vector<int>> result(row, vector<int>(col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
                else{ // grid[i][j] == 1
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return result;
    }
};
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        unordered_map<int, int> onesRow, onesCol;
        vector<vector<int>> result(row, vector<int>(col, 0));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                onesRow[i] += grid[i][j];
                onesCol[j] += grid[i][j];
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                result[i][j] = (2 * onesRow[i] - row) + (2 * onesCol[j] - col);
            }
        }

        return result;
    }
};