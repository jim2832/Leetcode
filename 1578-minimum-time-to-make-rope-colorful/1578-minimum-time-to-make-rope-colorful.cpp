/*

colors = "bbbaaa"
neededTime = [4,9,3,8,8,9]

*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int result = 0;

        for(int i=1; i<n; i++){
            if(colors[i-1] == colors[i]){
                result += min(neededTime[i-1], neededTime[i]);
                neededTime[i] = max(neededTime[i-1], neededTime[i]); // avoid using duplicated balloons
            }
        }

        return result;
    }
};