class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> starts, ends;

        for(auto &interval : intervals){
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int end_idx = 0, ans = 0;

        for(auto &start : starts){
            start > ends[end_idx] ? end_idx++ : ans++;
        }

        return ans;
    }
};