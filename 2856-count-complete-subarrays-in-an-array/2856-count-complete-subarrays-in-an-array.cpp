class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int start = 0, count = 0;
        unordered_map<int, int> hash;
        unordered_set<int> s(nums.begin(), nums.end());
        int m = s.size();
        
        for(int end = 0; end < n; end++){
            hash[nums[end]]++;

            while(hash.size() == m){
                count += n - end;

                hash[nums[start]]--;
                if(hash[nums[start]] == 0){
                    hash.erase(nums[start]);
                }
                start++;
            }
        }

        return count;
    }
};