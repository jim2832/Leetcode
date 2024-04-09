class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int upper = 0, lower = 0;
        string temp, result;

        for(auto &c : s){
            if(c == '('){
                upper++;
                temp += c;
            }
            else if(c == ')'){
                if(lower+1 <= upper){
                    lower++;
                    temp += c;
                }
            }
            else{
                temp += c;
            }
        }

        for(auto &c : temp){
            if(c == '('){
                if(lower == 0){
                    continue;
                }
                lower--;
            }
            result += c;
        }

        return result;
    }
};