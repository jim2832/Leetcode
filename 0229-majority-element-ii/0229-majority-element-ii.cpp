class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int restr = floor(n / 3);
        unordered_map<int, int> fre;
        vector<int> result;

        // count the frequency of every element
        for(int i=0; i<n; i++){
            fre[nums[i]]++;
        }
        
        for(auto &f:fre){
            if(f.second > restr){
                result.push_back(f.first);
            }
        }

        return result;
    }
};