class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto &num : nums) {
            if(num < k) return -1;
            s.insert(num);
        }

        s.erase(k);
        return s.size();
    }
};
