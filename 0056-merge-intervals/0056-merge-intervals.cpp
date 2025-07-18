class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= merged.back()[1]){  // overlap
                merged.back()[1] = max(intervals[i][1], merged.back()[1]);
            }
            else{
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};