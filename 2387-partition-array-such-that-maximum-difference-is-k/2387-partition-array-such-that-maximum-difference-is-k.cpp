class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cur_max = nums[0], cur_min = nums[0];
        int count = 0;

        for(auto &num : nums){
            cur_max = max(cur_max, num);
            cur_min = min(cur_min, num);
            if(cur_max - cur_min > k){
                count++;
                cur_max = cur_min = num;
            }
        }

        return count+1;
    }
};