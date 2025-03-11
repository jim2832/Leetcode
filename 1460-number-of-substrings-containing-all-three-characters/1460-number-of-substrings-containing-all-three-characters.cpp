class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> hash;
        int n = s.size();
        int start = 0;
        int count = 0;
        
        for(int end=0; end<n; end++){
            hash[s[end]]++;
            while(hash['a'] && hash['b'] && hash['c']){
                count += n - end;
                hash[s[start]]--;
                start++;
            }
        }

        return count;
    }
};