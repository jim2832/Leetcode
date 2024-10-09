class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        int count = 0;

        for(auto &c : s){
            if(c == '(') stack.push(c);
            else if(c == ')'){
                if(!stack.empty() && stack.top() == '(') stack.pop();
                else count++;
            }
        }

        return stack.size() + count;
    }
};