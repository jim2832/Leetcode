class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, j = 0;

        for(j=0; j<word.size(); j++){
            if(word[j] == ch) break;
        }

        if(j == word.size()) return word;

        reverse(word.begin(), word.begin()+j+1);

        return word;
    }
};