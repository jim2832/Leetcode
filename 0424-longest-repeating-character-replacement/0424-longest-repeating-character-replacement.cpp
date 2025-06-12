class Solution {
public:
    int characterReplacement(string s, int k) {
        int hashMap[26] = {0};
        int result = 0, max_freq = 0;

        for(int start = 0, end = 0; end < s.size(); end++){
            hashMap[s[end] - 'A']++;
            max_freq = max(max_freq, hashMap[s[end] - 'A']);

            while((end - start + 1) - max_freq > k){
                hashMap[s[start] - 'A']--;
                start++;
            }

            result = max(result, end - start + 1);
        }

        return result;
    }
};