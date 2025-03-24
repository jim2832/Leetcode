class Solution{
public:
    int countDays(int days, vector<vector<int>>& meetings){
        sort(meetings.begin(), meetings.end());

        int n = meetings.size();
        int start = meetings[0][0];
        int end = meetings[0][1];
        
        for(int i=0; i<n-1; i++){
            // overlap
            if(meetings[i+1][0] <= end){
                end = max(end, meetings[i+1][1]);
            }
            else{
                days -= (end - start + 1);
                start = meetings[i+1][0];
                end = meetings[i+1][1];
            }
        }

        return days - (end - start + 1);
    }
};
