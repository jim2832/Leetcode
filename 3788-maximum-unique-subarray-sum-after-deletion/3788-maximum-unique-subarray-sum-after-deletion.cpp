class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = 0;
        int max_ele = INT_MIN;
        unordered_set<int> us;

        for(int num : nums){
            max_ele = max(max_ele, num);
            if(!us.count(num) && num > 0){
                sum += num;
                us.insert(num);
            }
        }

        return max_ele < 0 ? max_ele : sum;
    }
};