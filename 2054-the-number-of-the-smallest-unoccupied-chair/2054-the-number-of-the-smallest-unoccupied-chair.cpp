#define DS pair<int, int>

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<DS> arrivals;
        for(int i=0; i<n; i++){
            arrivals.push_back({times[i][0], i});
        }

        sort(arrivals.begin(), arrivals.end());

        // min_heap to track the available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for(int i=0; i<n; i++){
            availableChairs.push(i);
        }

        // min_heap to track when chairs are freed
        priority_queue<DS, vector<DS>, greater<DS>> leavingQueue;

        for(auto &arrival : arrivals){
            int arrival_time = arrival.first;
            int arrival_index = arrival.second;

            // update the free chair
            while(!leavingQueue.empty() && leavingQueue.top().first <= arrival_time){
                availableChairs.push(leavingQueue.top().second);
                leavingQueue.pop();
            }

            // find the smallest chair which is available
            int chair = availableChairs.top();
            availableChairs.pop();

            if(arrival_index == targetFriend){
                return chair;
            }

            // Mark the chair as being used until the friend's leave time
            leavingQueue.push({times[arrival_index][1], chair});
        }


        return -1;
    }
};