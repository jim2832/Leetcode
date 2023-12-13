class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> hash; // number : index
        
        // record the position of every element
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]] = i;
        }

        // change the element
        for(int i=0; i<operations.size(); i++){
            int pos = hash[operations[i][0]]; // index
            nums[pos] = operations[i][1];
            hash[operations[i][1]] = pos;
        }

        return nums;
    }
};