// [5,1,3] -> [1,3,5]
// [1,3,3] -> [1,1,3] -> [1,1,1] (3)

// [1,1,2,2,3]
// [1,1,2,2,2] -> [1,1,1,2,2] -> [1,1,1,1,2] -> [1,1,1,1,1] (4)

// [5,1,3] -> [5,3,1]

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ope = 0;
        int accumulation = 0; // accumulative operation

        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                accumulation++;
            }
            ope += accumulation;
        }

        return ope;
    }
};