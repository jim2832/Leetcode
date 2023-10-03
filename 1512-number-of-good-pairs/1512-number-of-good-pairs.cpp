class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        // burte force
        /*
        int good = 0;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] == nums[j]){
                    good++;
                }
            }
        }

        return good;
        */

        // another approach
        int good = 0;
        unordered_map<int, int> fre;

        for(int i=0; i<nums.size(); i++){
            good += fre[nums[i]];
            fre[nums[i]]++;
        }

        return good;
    }
};