/*

[4,5,6,7,0,1,2]
[2,4,5,6,7,0,1]
[7,0,1,2,4,5,6]

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;

        while(start < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end]){
                start = mid + 1; //往右找
            }
            else{ // nums[mid] < nums[end]
                end = mid; //往左找
            }
        }

        return nums[start];
    }
};