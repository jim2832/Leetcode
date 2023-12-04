class Solution {
public:
    bool isSafe(int i, int j, int row, int col){
        return (i>=0 && i<row && j>=0 && j<col);
    }

    bool isBorder(int i, int j, int row, int col){
        return (i==0 || i==row-1 || j==0 || j==col-1);
    }

    void solve(vector<vector<char>>& board) {
        // edge case
        if(board.size() == 0){
            return;
        }

        // row and col
        int row = board.size();
        int col = board[0].size();

        // data structure
        queue<pair<int, int>> q; // BFS queue
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // direction

        // check the boundary
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O' && isBorder(i,j,row,col)){
                    board[i][j] = '.';
                    q.push({i,j});
                }
            }
        }

        // BFS
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            // check every directions
            for(int i=0; i<4; i++){
                int x = current.first + dir[i].first;
                int y = current.second + dir[i].second;
                if(isSafe(x,y,row,col) && !isBorder(x,y,row,col) && board[x][y] == 'O'){
                    board[x][y] = '.';
                    q.push({x,y});
                }
            }
        }

        // final convertion
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                // the remaining 'O'
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};