class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long lower = 0, upper = 1e12;

        while(lower < upper){
            long long mid = lower + (upper - lower + 1) / 2;

            long long piles = 0;
            for(int i=0; i<candies.size(); i++){
                piles += candies[i] / mid;
            }
            
            if(piles < k){
                upper = mid - 1;
            }
            else{
                lower = mid;
            }
        }

        return lower;
    }
};