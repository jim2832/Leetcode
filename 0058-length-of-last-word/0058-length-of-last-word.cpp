class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool encounter = false;

        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ' ' && encounter){
                break;
            }
            if(s[i] != ' '){
                encounter = true;
                count++;
            }
        }
        return count;
    }
};