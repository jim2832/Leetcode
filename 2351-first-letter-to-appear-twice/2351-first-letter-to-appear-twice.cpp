class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> hash;
        char result;

        for(int i=0; i<s.size(); i++){
            if(++hash[s[i]] == 2){
                result = s[i];
                break;
            }
        }

        return result;
    }
};