class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        string result = "";

        for(int i=0; i<s.size(); i++){
            if(s[i] == '*'){
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }

        while(!stack.empty()){
            result += stack.top();
            stack.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};