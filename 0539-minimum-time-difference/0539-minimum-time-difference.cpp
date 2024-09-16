class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        int mini = INT_MAX;
        vector<int> minutes;

        for(auto &timePoint : timePoints){
            int hour = stoi(timePoint.substr(0,2));
            int minute = stoi(timePoint.substr(3,2));
            minutes.push_back(60 * hour + minute);
        }

        sort(minutes.begin(), minutes.end());
        minutes.push_back(minutes[0] + 1440);
        
        for(int i=1; i<n+1; i++){
            mini = min(mini, minutes[i] - minutes[i-1]);
        }

        return mini;
    }
};