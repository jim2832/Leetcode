class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int maxi = 0;

        for(auto &num : nums){
            hashMap[num]++;
        }

        for(auto &[num, f] : hashMap){
            if(hashMap.count(num + 1)){
                maxi = max(maxi, f + hashMap[num + 1]);
            }
        }

        return maxi;
    }
};