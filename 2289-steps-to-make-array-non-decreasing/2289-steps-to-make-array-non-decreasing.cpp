class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> stack;
        int n = nums.size();
        int count = 0;
        int result = 0;

        for(int i=n-1; i>=0; i--){
            while(!stack.empty() && nums[i] > nums[stack.top().first]){
                count = max(count+1, stack.top().second);
                stack.pop();
            }
            stack.push({i, count});
            result = max(result, count);
            count = 0;
        }

        return result;
    }
};