class Solution{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
        int row = box.size();
        int col = box[0].size();
        
        vector<vector<char>> res(col, vector<char>(row, '.'));
        
        for(int r=0; r<row; r++){
            int i = col - 1;
            for(int c=col-1; c>=0; c--){
                if(box[r][c] == '#'){
                    res[i][row - r - 1] = '#';
                    i--;
                }
                else if(box[r][c] == '*'){
                    res[c][row - r - 1] = '*';
                    i = c - 1;
                }
            }
        }
        
        return res;
    }
};