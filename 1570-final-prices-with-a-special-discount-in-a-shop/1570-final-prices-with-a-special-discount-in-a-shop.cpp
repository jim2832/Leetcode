class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> stack;
        vector<int> result(n);

        for(int i=n-1; i>=0; i--){
            while(!stack.empty() && prices[i] < prices[stack.top()]) stack.pop();
            result[i] = stack.empty() ? prices[i] : prices[i] - prices[stack.top()];
            stack.push(i);
        }

        return result;
    }
};