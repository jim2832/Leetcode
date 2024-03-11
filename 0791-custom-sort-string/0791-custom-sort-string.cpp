class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> hash;
        string result;

        // init
        for(auto &c : order){
            hash[c] = 0;
        }

        // count the freq of character in s
        for(auto &c : s){
            if(hash.find(c) != hash.end()){
                hash[c]++;
            }
        }

        // insert the character that exist
        for(auto &c : order){
            result.append(hash[c], c);
        }

        // insert the character that doesn't exist
        for(auto &c : s){
            if(hash.find(c) == hash.end()){
                result += c;
            }
        }

        return result;
    }
};