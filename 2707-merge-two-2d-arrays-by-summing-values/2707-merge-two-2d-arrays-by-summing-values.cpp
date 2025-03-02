class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> hash;
        vector<vector<int>> result;

        for(auto &num : nums1) hash[num[0]] += num[1];
        for(auto &num : nums2) hash[num[0]] += num[1];
        for(auto &[id, val] : hash) result.push_back({id, val});

        return result;
    }
};