class Solution {
public:
    bool DFS(int i, int j, vector<vector<char>>& board, int index, const string &word){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;
        if(board[i][j] != word[index]) return false;

        if(index == word.size() - 1) return true; // matched

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = DFS(i, j+1, board, index+1, word) ||
                    DFS(i+1, j, board, index+1, word) ||
                    DFS(i, j-1, board, index+1, word) ||
                    DFS(i-1, j, board, index+1, word);
        
        // backtracking
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(DFS(i, j, board, 0, word)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};