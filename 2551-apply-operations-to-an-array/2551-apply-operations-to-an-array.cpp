class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        vector<int> result;

        for(int i=0; i<n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        for(auto &num : nums){
            if(num) result.push_back(num);
            else zero++;
        }

        for(int i=0; i<zero; i++){
            result.push_back(0);
        }

        return result;
    }
};