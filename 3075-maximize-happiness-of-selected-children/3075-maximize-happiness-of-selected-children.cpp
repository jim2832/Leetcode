class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());

        for(int i=0; i<k; i++){
            happiness[i] -= i;
            if(happiness[i] > 0) sum += happiness[i];
        }

        return sum;
    }
};