class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for(int i=0; i<t.size(); i++){
            hash[t[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            hash[s[i]]--;
        }
        for(auto h:hash){
            if(h.second == 1){
                return h.first;
            }
        }

        return 'a';
    }
};