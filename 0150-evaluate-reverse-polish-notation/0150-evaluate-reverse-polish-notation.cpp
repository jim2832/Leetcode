class Solution {
public:
    stack<string> s;

    int evalRPN(vector<string> &tokens){
        for(string c:tokens){
            //operator
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                //handle operand
                int op2 = stoi(s.top());
                s.pop();
                int op1 = stoi(s.top());
                s.pop();

                //declare temp result
                int temp = 0;

                //operation
                if(c == "+"){
                    temp = op1 + op2;
                    s.push(to_string(temp));
                }
                else if(c == "-"){
                    temp = op1 - op2;
                    s.push(to_string(temp));
                }
                else if(c == "*"){
                    temp = op1 * op2;
                    s.push(to_string(temp));
                }
                // '/'operator
                else{
                    temp = op1 / op2;
                    s.push(to_string(temp));
                }
            }
            //operand
            else{
                s.push(c);
            }
        }

        return stoi(s.top());
    }
};