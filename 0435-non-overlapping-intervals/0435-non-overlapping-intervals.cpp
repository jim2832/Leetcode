class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), count = 0;
        int end = intervals[0][1];

        for(int i = 1; i < n; i++){
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];

            if(next_start < end){
                count++;
                end = min(end, next_end);
            }
            else{
                end = next_end;
            }
        }

        return count;
    }
};