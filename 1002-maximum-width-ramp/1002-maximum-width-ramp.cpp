class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> stack;

        for(int i=0; i<n; i++){
            if(stack.empty() || nums[stack.top()] > nums[i]){
                stack.push(i);
            }
        }

        int maxi = 0;

        for(int i=n-1; i>=0; i--){
            while(!stack.empty() && nums[stack.top()] <= nums[i]){
                maxi = max(maxi, i - stack.top());
                stack.pop();
            }
        }

        return maxi;
    }
};