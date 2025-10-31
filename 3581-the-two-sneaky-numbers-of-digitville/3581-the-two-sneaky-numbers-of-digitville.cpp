class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        vector<int> result;

        for(int num : nums){
            if(++hashMap[num] > 1){
                result.push_back(num);
            }
        }

        return result;
    }
};