/*

capacity  = [2,3,4,5]
rocks     = [1,2,4,4]
remaining = [1,1,0,1]

*/

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remaining(n); // the remaining capacity of bags
        int result = 0;

        // calculate the remaining capacity
        for(int i=0; i<n; i++){
            remaining[i] = capacity[i] - rocks[i];
        }

        // sort the remaining vector
        sort(remaining.begin(), remaining.end());

        // use greedy approach to fill the bag
        for(auto &rock:remaining){
            // additionalRocks are not enough
            if(additionalRocks - rock < 0){
                break;
            }
            additionalRocks -= rock;
            result++;
        }

        return result;
    }
};