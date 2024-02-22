/*
[9,20,20,1]
[c,b, c, d]
*/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        for(int i=n-1; i>=1; i--){
            releaseTimes[i] -= releaseTimes[i-1];
        }

        int maxi = -INT_MAX;
        char result = '.';
        for(int i=0; i<n; i++){
            if(maxi < releaseTimes[i]){
                maxi = releaseTimes[i];
                result = keysPressed[i];
            }
            else if(maxi == releaseTimes[i] && keysPressed[i] > result){
                result = keysPressed[i];
            }
        }

        return result;
    }
};