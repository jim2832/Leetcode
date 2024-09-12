class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = words.size();
        unordered_set<char> s;

        for(auto &c : allowed) s.insert(c);

        for(auto &word : words){
            for(auto &c: word){
                if(!s.count(c)){
                    count--;
                    break;
                }
            }
        }

        return count;
    }
};