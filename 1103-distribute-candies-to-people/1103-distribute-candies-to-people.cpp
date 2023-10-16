class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> distribution(num_people, 0);
        int amount_now = 1;
        int i = 0;

        while(candies){
            if(i >= num_people){
                i = 0;
            }
            if(amount_now >= candies){
                distribution[i] += candies;
                break;
            }
            else{
                distribution[i] += amount_now;
            }
            candies -= amount_now;
            amount_now++;
            i++;
        }

        return distribution;
    }
};