class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        string result;

        for(int i=0; i<s.size(); i++){
            if(!stack.empty() && s[i] == stack.top()){
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