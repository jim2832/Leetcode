class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, len = 0;

        for(int num : nums){
            if(num == 0){
                len++;
                count += len;
            }
            else{
                len = 0;
            }
        }

        return count;
    }
};