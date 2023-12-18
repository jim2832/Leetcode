/*

[3,2,2,1] -> [1,2,2,3]

*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0;

        int start = 0, end = people.size()-1;
        while(start <= end){
            // if the thinest and heaviest person can sit together
            if(people[start] + people[end] <= limit){
                start++;
                end--;
            }
            // the heaviest person can only sit by himself
            else{
                end--;
            }
            count++;
        }

        return count;
    }
};