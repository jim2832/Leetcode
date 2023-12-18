class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        int count = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                stack.push('(');
            }
            else{
                if(stack.empty()){
                    count++;
                }
                else{
                    stack.pop();
                }
            }
        }

        while(!stack.empty()){
            stack.pop();
            count++;
        }

        return count;
    }
};