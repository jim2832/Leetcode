class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odds, evens;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2){
                odds.push_back(nums[i]);
            }
            else{
                evens.push_back(nums[i]);
            }
        }

        int i=0, j=0; // i->even, j->odd
        for(int k=0; k<nums.size(); k++){
            if(k % 2){
                result.push_back(odds[j]);
                j++;
            }
            else{
                result.push_back(evens[i]);
                i++;
            }
        }
        
        return result;
    }
};