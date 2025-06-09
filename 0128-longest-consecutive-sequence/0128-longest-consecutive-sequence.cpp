class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        
        for(auto &num : us){
            if(!us.count(num - 1)){
                int len = 1;
                int current = num;

                while(us.count(current + 1)){
                    current++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};