class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // [3,5,4,2,4,6]
        // [2,3,4,4,5,6]
        int max = -INT_MAX; // answer
        sort(nums.begin(), nums.end()); // sort the array

        int left = 0, right = nums.size()-1; // two pointers

        while(left < right){
            if(max < nums[left] + nums[right]){
                max = nums[left] + nums[right];
            }
            left++;
            right--;
        }

        return max;
    }
};