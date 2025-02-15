class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for(auto &word : words){
            int i = 0, j = 0;
            while(i < word.size() && j < pref.size() && word[i] == pref[j]){
                i++;
                j++;
            }
            if(j == pref.size()){
                count++;
                continue;
            }
        }

        return count;
    }
};