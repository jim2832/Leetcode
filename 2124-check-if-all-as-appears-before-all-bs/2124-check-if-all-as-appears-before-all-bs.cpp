class Solution {
public:
    bool checkString(string s) {
        bool encounter = false; // if we have encountered "b"
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'a'){
                if(encounter){
                    return false;
                }
                else{
                    continue;
                }
            }
            else{ //s[i] == b
                encounter = true;
            }
        }

        return true;
    }
};