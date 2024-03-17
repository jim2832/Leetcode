class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int new_start = newInterval[0];
        int new_end = newInterval[1];

        int i = 0;
        int n = intervals.size();

        // 重疊之前
        while(i < n && new_start > intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }

        // 重疊之間
        while(i < n && new_end >= intervals[i][0]){
            new_start = min(new_start, intervals[i][0]);
            new_end = max(new_end, intervals[i][1]);
            i++;
        }
        result.push_back({new_start, new_end});

        // 重疊之後
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};