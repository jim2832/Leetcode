class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;

        for(int &num:nums){
            if(num == 0){
                count++;
            }
        }
        
        // remove all 0
        nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());

        // push 0 at the end of the vector
        for(int i=0; i<count; i++){
            nums.push_back(0);
        }
    }
};