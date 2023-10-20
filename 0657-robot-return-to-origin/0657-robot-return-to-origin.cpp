class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char, int> hash;
        for(char &c:moves){
            hash[c]++;
        }

        return hash['U'] == hash['D'] && hash['L'] == hash['R'];
    }
};