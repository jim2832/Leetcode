/*
要知道一格內有多少積水，要先往前找最大值和往後找最大值
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;

        int n = height.size();
        stack<int> stack; // Monotonic Stack
        vector<int> backward_max(n), forward_max(n);

        // 找前面的最大值
        for(int i=0; i<n; i++){
            while(!stack.empty() && height[i] >= height[stack.top()]){
                stack.pop();
            }
            // 如果沒了就是自己
            if(stack.empty()){
                stack.push(i);
            }
            backward_max[i] = stack.top();
        }

        // 清空 stack
        while(!stack.empty()){
            stack.pop();
        }

        // 找後面的最大值
        for(int i=n-1; i>=0; i--){
            while(!stack.empty() && height[i] >= height[stack.top()]){
                stack.pop();
            }
            // 如果沒了就是自己
            if(stack.empty()){
                stack.push(i);
            }
            forward_max[i] = stack.top();
        }

        for(int i=0; i<n; i++){
            result += min(height[backward_max[i]], height[forward_max[i]]) - height[i];
        }

        return result;
    }
};