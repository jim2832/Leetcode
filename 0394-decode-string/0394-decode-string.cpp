/*
class Solution{
public:
    string decodeString(string s){
        stack<char> stack;
        
        for(auto &c : s){
            if(c == ']'){
                // 處理要重複的字串
                string repeated_str;
                while(!stack.empty() && stack.top() != '['){
                    repeated_str = stack.top() + repeated_str;
                    stack.pop();
                }
                stack.pop(); // pop 掉 "["

                // 處理重複次數的數字
                int num = 0, incre = 1;
                while(!stack.empty() && isdigit(stack.top())){
                    num = (stack.top() - '0') * incre + num;
                    incre *= 10;
                    stack.pop();
                }

                // 將重複的字串加入堆疊
                string expanded_str;
                for(int i=0; i<num; i++){
                    expanded_str += repeated_str;
                }

                // 將處理好字串的每個字元推回stack
                for(auto &c : expanded_str){
                    stack.push(c);
                }
            }
            else{
                stack.push(c);
            }
        }

        // 組合最終結果
        string result;
        while(!stack.empty()){
            result = stack.top() + result;
            stack.pop();
        }

        return result;
    }
};
*/

class Solution{
public:
    string decodeString(string s){
        stack<string> strStack; // 用來儲存字串
        stack<int> numStack;    // 用來儲存數字
        string currentStr;      // 當前的字串片段
        int num = 0;            // 當前的數字

        for(auto &c : s){
            if(isdigit(c)){
                // 如果是數字，更新 num
                num = num * 10 + (c - '0');
            }
            else if(c == '['){
                // 遇到 '[', 儲存當前的字串和數字
                strStack.push(currentStr);
                numStack.push(num);
                // 重置 num 和 currentStr
                num = 0;
                currentStr.clear();
            }
            else if(c == ']'){
                // 遇到 ']', 展開字串
                string temp = currentStr;
                int repeatCount = numStack.top();
                numStack.pop();

                // 重複 temp，並加回到之前的字串片段
                currentStr = strStack.top();
                strStack.pop();
                while(repeatCount--){
                    currentStr += temp;
                }
            }
            else{
                // 如果是普通字母，加到當前字串
                currentStr += c;
            }
        }

        return currentStr;
    }
};