// Consider the following equation: x ^ a = b. How can you find x?
// -> x = a ^ b

// arr[i] ^ pref[i-1] = pref[i]
// -> arr[i] = pref[i] ^ pref[i-1]

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        for(int i=pref.size()-1; i>=1; i--){
            pref[i] ^= pref[i-1];
        }

        return pref;
    }
};