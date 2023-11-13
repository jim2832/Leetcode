class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(); // row
        int n = grid[0].size(); // column

        int count = 0; // negative number count
        int i = 0, j = n-1; // start(從右上開始)
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j] < 0){
                count += m-i; //如果此點<0，則他下面的點必<0
                j--; //往左移動
            }
            else{
                i++; //往下移動
            }
        }

        return count;
    }
};