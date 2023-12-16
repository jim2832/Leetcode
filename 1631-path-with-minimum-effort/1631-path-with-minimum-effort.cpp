class Solution {
public:
    bool is_valid(int x, int y, int row, int col){
        return x>=0 && x<row && y>=0 && y<col;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0,0}});
        vector<vector<bool>> visited(row, vector<bool>(col, 0)); // check if the grid is visited
        int maxi = -INT_MAX;

        // BFS
        while(!pq.empty()){
            auto current = pq.top();
            pq.pop();

            int weight = current.first;
            int x = current.second.first;
            int y = current.second.second;
            maxi = max(maxi, weight);
            visited[x][y] = true;
            if(x == row-1 && y == col-1){
                return maxi;
            }

            vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
            for(int i=0; i<4; i++){
                int new_x = x + dirs[i].first;
                int new_y = y + dirs[i].second;
                if(is_valid(new_x, new_y, row, col) && !visited[new_x][new_y]){
                    pq.push({abs(heights[new_x][new_y] - heights[x][y]), {new_x, new_y}});
                }
            }
        }

        return maxi;
    }
};