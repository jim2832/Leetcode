class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> hash;
        int result = 0;

        for(auto &c:chars){
            hash[c]++;
        }

        // check the number of the frequency of the character
        for(int i=0; i<words.size(); i++){
            // check every word
            unordered_map<char, int> temp;
            bool flag = true;
            for(auto &c:words[i]){
                temp[c]++;
            }
            for(auto iter=temp.begin(); iter!=temp.end(); iter++){
                if(hash.find(iter->first) == hash.end() || hash[iter->first] < iter->second){
                    flag = false;
                    break;
                }
            }
            if(flag)
                result += words[i].size();
        }

        return result;
    }
};