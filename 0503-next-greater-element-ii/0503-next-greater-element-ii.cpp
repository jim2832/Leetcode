class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> result(n);
        stack<int> stack;
        
        for(int i=2*n-1; i>=0; i--){
            while(!stack.empty() && nums[i] >= stack.top()){
                stack.pop();
            }
            if(i < n){
                result[i] = stack.empty() ? -1 : stack.top();
            }
            stack.push(nums[i]);
        }

        return result;
    }
};