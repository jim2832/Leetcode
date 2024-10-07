class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        char temp;

        for(auto &c : s){
            stack.push(c);
            if(c == 'B' && stack.size() > 1){
                temp = c;
                stack.pop();
                if(stack.top() == 'A'){
                    stack.pop();
                }
                else{
                    stack.push(temp);
                }
            }
            if(c == 'D' && stack.size() > 1){
                temp = c;
                stack.pop();
                if(stack.top() == 'C'){
                    stack.pop();
                }
                else{
                    stack.push(temp);
                }
            }
            // cout << stack.top();
        }

        return stack.size();
    }
};