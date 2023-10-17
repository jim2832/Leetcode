class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> hash;
        int num = 1;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }
        while(hash.find(num) != hash.end()){
            num++;
        }

        return num;
    }
};