class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int start = 0;
        int max_size = 0;

        for(int end=0; end<n; end++){
            int cur_num = nums[end];
            hash[cur_num]++;

            while(hash[cur_num] > k){
                hash[nums[start]]--;
                start++;
            }

            max_size = max(max_size, end - start + 1);
        }

        return max_size;
    }
};