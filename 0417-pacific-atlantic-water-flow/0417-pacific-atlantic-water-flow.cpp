class Solution {
public:
    void DFS(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j){
        int row = heights.size();
        int col = heights[0].size();

        visited[i][j] = 1;

        if(i>0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j]){ //up
            DFS(heights, visited, i-1, j);
        }
        if(i<row-1 && !visited[i+1][j] && heights[i+1][j] >= heights[i][j]){ //down
            DFS(heights, visited, i+1, j);
        }
        if(j>0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j]){ //left
            DFS(heights, visited, i, j-1);
        }
        if(j<col-1 && !visited[i][j+1] && heights[i][j+1] >= heights[i][j]){ //right
            DFS(heights, visited, i, j+1);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<int>> result;

        // record the grid flow into ocean or not
        vector<vector<int>> Pacific(row, vector<int>(col));
        vector<vector<int>> Atlantic(row, vector<int>(col));

        for(int i=0; i<row; i++){
            DFS(heights, Pacific, i, 0);
            DFS(heights, Atlantic, i, col-1);
        }

        for(int j=0; j<col; j++){
            DFS(heights, Pacific, 0, j);
            DFS(heights, Atlantic, row-1, j);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};