class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        string s_alt = "", t_alt = "";

        for(char &c:s){
            if(c == '#'){
                if(!s1.empty()){
                    s1.pop();
                }
            }
            else{
                s1.push(c);
            }
        }

        for(char &c:t){
            if(c == '#'){
                if(!s2.empty()){
                    s2.pop();
                }
            }
            else{
                s2.push(c);
            }
        }

        while(!s1.empty()){
            s_alt += s1.top();
            s1.pop();
        }

        while(!s2.empty()){
            t_alt += s2.top();
            s2.pop();
        }

        return s_alt == t_alt;
    }
};