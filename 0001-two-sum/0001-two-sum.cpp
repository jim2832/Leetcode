class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> record;
            vector<int> result;

            for(int i=0; i<nums.size(); i++){
                int diff = target - nums[i];
                if(record.find(diff) != record.end()){
                    result.push_back(record[diff]);
                    result.push_back(i);
                }
                record[nums[i]] = i;

            }

            return result;
        }
};