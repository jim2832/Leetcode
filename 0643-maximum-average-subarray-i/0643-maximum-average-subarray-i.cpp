class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_sum = 0, cur_sum = 0;
        
        for(int i=0; i<k; i++){
            cur_sum += nums[i];
        }
        max_sum = cur_sum;

        for(int i=k; i<nums.size(); i++){
            cur_sum += nums[i] - nums[i-k];
            max_sum = cur_sum > max_sum ? cur_sum : max_sum;
        }

        return max_sum / k;
    }
};