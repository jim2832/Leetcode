using DS = tuple<int, int, int>;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
public:
    bool is_outside(int i, int j, int n, int m){
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<DS, vector<DS>, greater<DS>> pq;

        // start at (0,0) with time 0
        pq.emplace(0, 0, 0);
        time[0][0] = 0;

        while(!pq.empty()){
            auto [i, j, t] = pq.top();
            pq.pop();

            // reached
            if(i == n - 1 && j == m - 1){
                return t;
            }

            for(int k = 0; k < 4; k++){
                int r = i + directions[k].first;
                int c = j + directions[k].second;
                if(is_outside(r, c, n, m)) continue;

                // min time to reach (r,s)
                int next_time = max(t, moveTime[r][c]) + 1;

                // update
                if(time[r][c] > next_time){
                    time[r][c] = next_time;
                    pq.emplace(r, c, next_time);
                }
            }
        }

        return -1;
    }
};