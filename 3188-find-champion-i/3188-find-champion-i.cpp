class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int ans;

        for(int i=0; i<grid.size(); i++){
            bool flag = true;
            for(int j=0; j<grid[i].size(); j++){
                if(!grid[i][j] && j != i) flag = false;
            }
            if(flag){
                ans = i;
                break;
            }
        }

        return ans;
    }
};