class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;
        int new_start = newInterval[0];
        int new_end = newInterval[1];
        bool inserted = false;

        for(auto &interval : intervals) {
            if(interval[1] < new_start) {
                merged.push_back(interval);
            }
            else if(interval[0] > new_end) {
                if(!inserted) {
                    merged.push_back({new_start, new_end});
                    inserted = true;
                }
                merged.push_back(interval);
            }
            else {
                new_start = min(new_start, interval[0]);
                new_end = max(new_end, interval[1]);
            }
        }

        if(!inserted) {
            merged.push_back({new_start, new_end});
        }

        return merged;
    }
};
