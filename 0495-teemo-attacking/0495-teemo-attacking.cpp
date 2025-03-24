class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum = 0;

        for(int i=0; i<timeSeries.size()-1; i++){
            // overlap
            if(timeSeries[i] + duration - 1 >= timeSeries[i+1]){
                sum += timeSeries[i+1] - timeSeries[i];
            }
            else{
                sum += duration;
            }
        }

        return sum + duration;
    }
};