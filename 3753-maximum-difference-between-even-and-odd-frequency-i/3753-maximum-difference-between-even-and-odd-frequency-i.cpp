class Solution {
public:
    int maxDifference(string s) {
        int hashMap[26] = {0};
        int maxi = INT_MIN, mini = INT_MAX;

        for(auto &c : s){
            hashMap[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(hashMap[i] == 0) continue;
            if(hashMap[i] % 2){
                maxi = max(maxi, hashMap[i]);
            }
            else{
                mini = min(mini, hashMap[i]);
            }
        }

        return maxi - mini;
    }
};