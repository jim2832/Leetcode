class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long result = 0;
        const int mod = 1e9 + 7;
        long long hashMap[26] = {0};

        for(auto &c : s){
            hashMap[c - 'a']++;
        }

        while(t--){
            long long temp[26] = {0};
            for(int i = 0; i < 26; i++){
                if(i == 25){ // z
                    temp[0] = (temp[0] + hashMap[25]) % mod;
                    temp[1] = (temp[1] + hashMap[25]) % mod;
                }
                else{
                    temp[i+1] = (temp[i+1] + hashMap[i]) % mod;
                }
            }
            memcpy(hashMap, temp, sizeof(hashMap));
        }

        for(auto &ele : hashMap){
            result = (result + ele) % mod;
        }

        return result;
    }
};