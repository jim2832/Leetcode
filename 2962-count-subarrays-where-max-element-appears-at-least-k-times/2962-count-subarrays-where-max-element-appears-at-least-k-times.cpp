class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // find the maximal element
        int max_ele = -INT_MAX;
        for(auto &num : nums){
            max_ele = max(max_ele, num);
        }

        long long count = 0;
        int max_ele_freq = 0;

        int n = nums.size();
        int start = 0;
        for(int end=0; end<n; end++){
            if(nums[end] == max_ele){
                max_ele_freq++;
            }

            while(max_ele_freq >= k){
                if(nums[start] == max_ele){
                    max_ele_freq--;
                }
                start++;
            }

            count += start;
        }

        return count;
    }
};