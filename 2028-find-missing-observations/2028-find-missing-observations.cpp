class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (n + m);
        for(auto &roll : rolls) sum -= roll;

        double test = (double)sum / n;
        if(1 <= test && test <= 6){
            vector<int> result;
            int temp = n; // current n (dynamic)
            for(int i=0; i<n; i++){
                int avg = sum / temp;
                result.push_back(avg);
                sum -= avg;
                temp--;
            }
            return result;
        }

        return {};
    }
};