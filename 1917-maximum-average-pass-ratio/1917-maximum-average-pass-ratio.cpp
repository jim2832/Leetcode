class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int,int>>> pq;
        double avg = 0;

        for(auto &c : classes){
            int pass = c[0], total = c[1];
            double change = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({change, {pass, total}});
        }

        while(extraStudents--){
            auto [change, info] = pq.top();
            pq.pop();
            int pass = info.first, total = info.second;
            pass++;
            total++;
            double new_change = (double)(pass+1)/(total+1) - (double)pass/total;
            pq.push({new_change, {pass, total}});
        }

        while(!pq.empty()){
            auto [change, info] = pq.top();
            pq.pop();
            int pass = info.first, total = info.second;
            avg += (double)pass / total;
        }

        return avg / classes.size();
    }
};