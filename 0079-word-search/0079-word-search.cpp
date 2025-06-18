class Solution{
public:
    bool DFS(int i, int j, vector<vector<char>>& board, const string& word, int cur_idx, vector<vector<bool>>& visited){
        int row = board.size();
        int col = board[0].size();

        // 越界 or 拜訪過 or 字母不符
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        if(visited[i][j]) return false;
        if(board[i][j] != word[cur_idx]) return false;

        // 所有字母都匹配成功
        if(cur_idx == word.size() - 1) return true;

        visited[i][j] = true; // 標記拜訪

        // 四個方向探索
        bool found = DFS(i+1, j, board, word, cur_idx+1, visited) ||
                     DFS(i-1, j, board, word, cur_idx+1, visited) ||
                     DFS(i, j+1, board, word, cur_idx+1, visited) ||
                     DFS(i, j-1, board, word, cur_idx+1, visited);

        visited[i][j] = false; // 回溯：解除標記
        return found;
    }

    bool exist(vector<vector<char>>& board, string word){
        int row = board.size();
        int col = board[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == word[0]){
                    if(DFS(i, j, board, word, 0, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
