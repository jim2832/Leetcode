class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int j = 0;
        for(auto &num:pushed){
            stack.push(num);
            while(!stack.empty() && stack.top() == popped[j]){
                stack.pop();
                j++;
            }
        }

        return stack.empty();
    }
};