class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0, neg = 0;
        int n = nums.size();
        int count = 0;
        vector<int> result;

        while(count < n / 2){
            // move pointer to the right position
            while(nums[pos] < 0){
                pos++;
            }
            while(nums[neg] > 0){
                neg++;
            }
            result.push_back(nums[pos]);
            result.push_back(nums[neg]);

            pos++;
            neg++;

            count++;
        }

        return result;
    }
};