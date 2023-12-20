/*

[3,2,1,2,1,7] -> 3+2+1+2+1+7=16
1+2+3+4+5+6 = 21

[3,2,1,2,1,7] sorting -> [1,1,2,2,3,7]
[1,1,2,2,3,7] -> [1,2,2,2,3,7] -> [1,2,3,2,3,7] -> [1,2,3,4,3,7] -> [1,2,3,4,5,7]

*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int incre = 0;

        for(int i=0; i<n-1; i++){
            if(nums[i+1] <= nums[i]){
                int temp = nums[i+1]; // original value
                nums[i+1] = nums[i] + 1;
                incre += nums[i+1] - temp; // new value - original value 
            }
        }

        return incre;
    }
};