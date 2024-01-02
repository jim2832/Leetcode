class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize two pointers and variables to store the answer and the previous count
        int i = -1, j = 0;
        int ans = 0;
        int prev = 0;

        // Iterate through the array using two pointers
        while (j < n) {

            // If the current element is within the specified range [left, right]
            if (nums[j] >= left and nums[j] <= right) {
                // Increment the answer by the number of subarrays ending at the current position
                ans += j - i;
                // Update the previous count
                prev = j - i;
            }

            // If the current element is less than the left bound
            else if (nums[j] <= left) {
                // Increment the answer by the previous count (subarrays ending at the previous position)
                ans += prev;
            }

            // If the current element is greater than the right bound
            else {
                // Reset the previous count
                prev = 0;
                // Move the left pointer to the current position
                i = j;
            }
            j++;
        }

        return ans;
    }
};