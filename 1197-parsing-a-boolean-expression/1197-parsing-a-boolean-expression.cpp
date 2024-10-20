class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stack;

        for(auto &c : expression){
            if(c == ',') continue;

            if(c == ')'){
                // 儲存待處理的 true 和 false
                vector<bool> result;
                while(stack.top() != '&' && stack.top() != '|' && stack.top() != '!'){
                    auto temp = stack.top();
                    stack.pop();
                    if(temp == 't') result.emplace_back(true);
                    if(temp == 'f') result.emplace_back(false);
                }

                // 處理邏輯字元
                auto temp = stack.top();
                stack.pop();
                if(temp == '&'){
                    bool temp_res = result[0];
                    for(int i=1; i<result.size(); i++) temp_res &= result[i];
                    stack.push(temp_res ? 't' : 'f');
                }
                else if(temp == '|'){
                    bool temp_res = result[0];
                    for(int i=1; i<result.size(); i++) temp_res |= result[i];
                    stack.push(temp_res ? 't' : 'f');
                }
                else if(temp == '!'){
                    stack.push(result[0] ? 'f' : 't');
                }
            }
            else{
                stack.push(c);
            }
        }

        return stack.top() == 't';
    }
};