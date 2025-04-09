class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int mini = *min_element(nums.begin(), nums.end());
            if(mini < k) return -1;
            
            unordered_set<int> s(nums.begin(), nums.end());
            return mini == k ? s.size()-1 : s.size();
        }
    };