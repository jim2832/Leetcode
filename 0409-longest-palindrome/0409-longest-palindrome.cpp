class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        int len = 0;
        bool odd = false;

        for(auto &c : s) hash[c]++;

        for(auto [c, freq] : hash){
            if(freq % 2 == 0){
                len += freq;
            }
            else{
                len += freq - 1;
                odd = true;
            }
        }

        return odd ? len+1 : len;
    }
};