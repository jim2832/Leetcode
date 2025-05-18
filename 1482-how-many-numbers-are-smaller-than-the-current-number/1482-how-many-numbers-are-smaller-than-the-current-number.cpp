class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        vector<int> temp = nums;
        int n = nums.size();

        sort(temp.begin(), temp.end()); // [1,2,2,3,8]
        
        for(int i = n-1; i >= 0; i--){
            hashMap[temp[i]] = i;
        }

        for(int i = 0; i < n; i++){
            nums[i] = hashMap[nums[i]];
        }

        return nums;
    }
};