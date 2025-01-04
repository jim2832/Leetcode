class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // record the first and last appearance of each character
        unordered_map<char, int> first, last;
        for(int i=0; i<s.size(); i++){
            if(first.find(s[i]) == first.end()) first[s[i]] = i;
            last[s[i]] = i;
        }

        // record every unique string
        unordered_set<string> unique_subs;
        for(auto &[c, start] : first){
            int end = last[c];
            if(end - start > 1){
                unordered_set<char> sett;
                for(int i=start+1; i<end; i++){
                    sett.insert(s[i]);
                }
                for(auto &ch : sett){
                    unique_subs.insert(string(1, c) + ch + c);
                }
            }
        }

        return unique_subs.size();
    }
};