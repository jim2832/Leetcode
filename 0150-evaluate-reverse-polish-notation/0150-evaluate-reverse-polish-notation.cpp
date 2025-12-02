class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        unordered_map<string, function<int(int,int)>> ops = {
            { "+", [](int a, int b){ return a + b; } },
            { "-", [](int a, int b){ return a - b; } },
            { "*", [](int a, int b){ return a * b; } },
            { "/", [](int a, int b){ return a / b; } },
        };

        for(string &t : tokens){
            if(ops.count(t)){
                int temp1 = stack.top();
                stack.pop();
                int temp2 = stack.top();
                stack.pop();
                stack.push(ops[t](temp2, temp1));
            }
            else{
                stack.push(stoi(t));
            }
        }

        return stack.top();
    }
};