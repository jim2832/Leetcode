class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> stack; // 存index

        for(int i=n-1; i>=0; i--){
            while(!stack.empty() && temperatures[i] >= temperatures[stack.top()]){
                stack.pop();
            }

            result[i] = stack.empty() ? 0 : stack.top() - i;
            stack.push(i);
        }

        return result;
    }
};