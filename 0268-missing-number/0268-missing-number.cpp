class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // [0,1,3]
        // [0,1,2,3,4,5,6,7,9]
        //  0 1 2 3 4 5 6 7 8

        for(int i=0; i<nums.size(); i++){
            if(i != nums[i]){
                return i;
            }
        }

        return nums.size();
    }
};