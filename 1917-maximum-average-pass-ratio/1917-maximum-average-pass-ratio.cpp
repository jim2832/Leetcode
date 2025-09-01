#define DS pair<double, pair<int, int>>

class Solution {
public:
    auto gain(int pass, int total){
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<DS> pq;
        double sum = 0;
        int n = classes.size();

        for(auto &c : classes){
            pq.push({gain(c[0], c[1]), {c[0], c[1]}});
        }

        while(extraStudents--){
            auto [g, p] = pq.top(); pq.pop();
            int pass = p.first, total = p.second;
            pass++;
            total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        while(!pq.empty()){
            auto [g, p] = pq.top(); pq.pop();
            sum += (double)p.first / p.second;
        }

        return sum / n;
    }
};
