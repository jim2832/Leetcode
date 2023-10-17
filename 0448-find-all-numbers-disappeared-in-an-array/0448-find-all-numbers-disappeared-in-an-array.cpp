class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        for(int i=1; i<=nums.size(); i++){
            if(hash.find(i) == hash.end()){
                result.push_back(i);
            }
        }

        return result;
    }
};