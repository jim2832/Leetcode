class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrive_time(n);

        for(int i=0; i<n; i++){
            arrive_time[i] = (double)dist[i] / speed[i];
        }
        
        sort(arrive_time.begin(), arrive_time.end());

        for(int i=0; i<n; i++){
            if(arrive_time[i] <= i){
                return i;
            }
        }

        return n;
    }
};