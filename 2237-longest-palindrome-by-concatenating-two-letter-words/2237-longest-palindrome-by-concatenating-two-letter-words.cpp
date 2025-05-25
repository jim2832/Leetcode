class Solution{
public:
    int longestPalindrome(vector<string>& words){
        unordered_map<string, int> hashMap;
        int len = 0;
        bool hasOddCenter = false;

        for(auto& word : words){
            hashMap[word]++;
        }

        for(auto &[s, f] : hashMap){
            string rev = s;
            reverse(rev.begin(), rev.end());

            if(s != rev){
                if(hashMap.find(rev) != hashMap.end()){
                    int pairCount = min(f, hashMap[rev]);
                    len += pairCount * 4;
                    hashMap[s] -= pairCount;
                    hashMap[rev] -= pairCount;
                }
            }
            else{
                len += (f / 2) * 4;
                if(f % 2) hasOddCenter = true;
            }
        }

        if(hasOddCenter) len += 2;

        return len;
    }
};
