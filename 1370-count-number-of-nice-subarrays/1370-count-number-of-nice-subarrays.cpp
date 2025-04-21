class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, odd_num = 0;
        int count = 0;

        for(int end = 0; end < n; end++){
            if(nums[end] % 2) odd_num++;

            while(odd_num > k){
                if(nums[start] % 2) odd_num--;
                start++;
            }

            count += end - start + 1;
        }

        return count;
    }
};