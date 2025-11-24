class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int current = 0;
        
        for(int n : nums){
            current = ((current <<= 1) + n) % 5;
            result.push_back(current == 0);
        }

        return result;
    }
};