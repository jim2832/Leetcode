/*
"dvdf" -> "vdf" (3)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us; // record the appearance of char
        int n = s.size(); // length of the string s
        int len = 0; // result
        int windowStart = 0, windowEnd = 0; // sliding window

        while(windowEnd < n){
            // not repeat
            if(us.find(s[windowEnd]) == us.end()){
                us.insert(s[windowEnd]);
                len = max(len, windowEnd - windowStart + 1);
                windowEnd++;
            }
            else{
                us.erase(us.find(s[windowStart]));
                windowStart++;
            }
        }

        return len;
    }
};