class Solution{
public:
    int maxEvents(vector<vector<int>>& events){
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;

        int i = 0, n = events.size();
        int day = 1;
        int count = 0;

        while(i < n || !pq.empty()){
            // add the events that have started
            while(i < n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            // remove events that have ended
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
            // attend the earliest event
            if(!pq.empty()){
                pq.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};
