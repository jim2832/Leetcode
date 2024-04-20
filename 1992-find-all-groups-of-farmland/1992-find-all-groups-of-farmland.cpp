class Solution {
public:
    bool outofbound(int i, int j, int row, int col){
        return (i < 0) || (i > row-1) || (j < 0) || (j > col-1);
    }

    void DFS(vector<vector<int>>& land, int i, int j, int &down, int &right){
        int row = land.size();
        int col = land[0].size();

        if(outofbound(i, j, row, col) || land[i][j] == 0) return;
        land[i][j] = 0;

        down = max(down, i);
        right = max(right, j);

        DFS(land, i+1, j, down, right);
        DFS(land, i-1, j, down, right);
        DFS(land, i, j+1, down, right);
        DFS(land, i, j-1, down, right);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int row = land.size();
        int col = land[0].size();
        vector<vector<int>> result;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(land[i][j]){
                    int up = i, left = j, down = i, right = j;
                    DFS(land, i, j, down, right);
                    result.push_back({up, left, down, right});
                }
            }
        }

        return result;
    }
};