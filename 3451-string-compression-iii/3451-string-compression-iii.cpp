class Solution {
public:
    string compressedString(string word) {
        string result;
        char prev = word[0];
        int count = 1;
        word += "@";

        for(int i=1; i<word.size(); i++){
            if(word[i] == prev && count < 9){
                count++;
            }
            else{
                result += to_string(count) + prev;
                count = 1;
                prev = word[i];
            }
        }

        return result;
    }
};