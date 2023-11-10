class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int ,int> hash;

        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
        }

        int sum = 0;
        for(int num:nums){
            if(hash[num] == 1){
                sum += num;
            }
        }

        return sum;
    }
};