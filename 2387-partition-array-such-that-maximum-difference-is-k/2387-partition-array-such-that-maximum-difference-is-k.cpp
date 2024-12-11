class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int cur_min = nums[0], cur_max = nums[0];

        for(auto &num : nums){
            if(num - cur_min <= k && cur_max - num <= k){
                cur_min = min(cur_min, num);
                cur_max = max(cur_max, num);
            }
            else{
                cur_min = num;
                cur_max = num;
                count++;
            }
        }

        return count;
    }
};