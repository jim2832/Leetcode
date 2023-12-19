/*

[1,5] -> [1,4] -> [0,4] -> [0,2] -> [0,1] -> [0,0]
[4,2,5] -> [4,2,4] -> [2,1,2] -> [2,0,2] -> [1,0,1] -> [0,0,1] -> [0,0,0]

*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ope = 0;
        int n = nums.size();

        while(true){
            int even_num = 0;
            int zero_num = 0;

            // traverse the vector once
            for(int i=0; i<n; i++){
                // odd
                if(nums[i] % 2 == 1){
                    nums[i]--;
                    ope++;
                }
                // even
                else{
                    even_num++;
                }
                // count the zero number to check if we can end
                if(nums[i] == 0){
                    zero_num++;
                }
            }

            // check if we can end
            if(zero_num == n){
                return ope;
            }

            // no odd number, all of the numbers in the vector are even
            if(even_num == n){
                ope++;
                for(auto &num:nums){
                    num /= 2;
                }
            }
        }

        return ope;
    }
};