#define DS pair<double, pair<int, int>>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<DS, vector<DS>, greater<DS>> pq; // <distance, <x, y>>
        vector<vector<int>> result;
        
        for(auto &point:points){
            int x = point[0];
            int y = point[1];
            double dist = sqrt(pow(x, 2) + pow(y, 2));
            pq.push({dist, {x, y}});
        }

        while(k--){
            auto current = pq.top();
            pq.pop();
            result.push_back({current.second.first, current.second.second});
        }

        return result;
    }
};