#define len

class Solution {
public:
    bool compare(string word1, string word2){
        return word1[0] == word2[1] && word1[1] == word2[0];
    }

    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++){
                if(compare(words[i], words[j])){
                    count++;
                }
            }
        }

        return count;
    }
};