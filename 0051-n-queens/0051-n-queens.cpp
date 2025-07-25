class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> nQueens(n, string(n, '.'));
        solve(result, nQueens, 0, n);

        return result;
    }

    void solve(vector<vector<string>> &result, vector<string> &nQueens, int row, int &n){
        if(row == n){
            result.push_back(nQueens);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(nQueens, row, col,  n)){
                nQueens[row][col] = 'Q';
                solve(result, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &nQueens, int row, int col, int &n){
        // top
        for(int i = 0; i < row; i++){
            if(nQueens[i][col] == 'Q') return false;
        }
        // top left
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(nQueens[i][j] == 'Q') return false;
        }
        // top right
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(nQueens[i][j] == 'Q') return false;
        }
        return true;
    }
};