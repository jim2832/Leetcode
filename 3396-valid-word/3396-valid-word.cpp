class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        bool vowel = false, consonant = false;

        for(char &w : word){
            if(isdigit(w)){
                continue;
            }
            else if(isalpha(w)){
                if(w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' ||
                    w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U'){
                    vowel = true;
                }
                else{
                    consonant = true;
                }
            }
            else{
                return false;
            }
        }
        
        return vowel && consonant;
    }
};