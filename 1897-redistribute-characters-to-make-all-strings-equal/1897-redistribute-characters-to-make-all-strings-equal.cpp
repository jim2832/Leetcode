/*

words = ["abc","aabc","bc"] -> ["abc","abc","abc"]

*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> hash; // the frequency of every character

        for(auto &str:words){
            for(char &c:str){
                hash[c]++;
            }
        }

        int n = words.size();
        for(auto &pair:hash){
            // checking if characters can be distributed equally
            if(pair.second % n != 0){
                return false;
            }
        }

        return true;
    }
};