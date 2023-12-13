class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<int> result;

        for(auto &num:nums){
            hash[num]++;
        }

        for(auto &num:nums){
            if(hash[num] == 1 && hash.find(num+1) == hash.end() && hash.find(num-1) == hash.end()){
                result.push_back(num);
            }
        }

        return result;
    }
};