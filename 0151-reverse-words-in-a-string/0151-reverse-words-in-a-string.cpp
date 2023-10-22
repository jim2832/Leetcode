class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string result = "";
        for(int i=0; i<s.size(); i++){
            string temp;
            if(s[i] == ' '){
                continue;
            }
            while(i < s.size() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            stk.push(temp);
        }

        while(!stk.empty()){
            if(stk.size() == 1){
                result += stk.top();
            }
            else{
                result = result + stk.top() + " ";
            }
            stk.pop();
        }

        return result;
    }
};