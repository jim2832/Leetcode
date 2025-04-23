class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0, len = 0;
        unordered_map<char, int> hash;

        for(int end = 0; end < n; end++){
            hash[s[end]]++;
            
            while(hash[s[end]] > 1){
                hash[s[start]]--;
                start++;
            }

            len = max(len, end - start + 1);
        }

        return len;
    }
};