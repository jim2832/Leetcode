class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int result = 0;
        int maxi = *max_element(costs.begin(), costs.end());
        vector<int> count(maxi + 1, 0);

        for(auto &cost : costs){
            count[cost]++;
        }

        for(int i = 1; i <= maxi; i++) {
            while(count[i] > 0 && coins >= i) {
                coins -= i;
                result++;
                count[i]--;
            }
        }

        return result;
    }
};
