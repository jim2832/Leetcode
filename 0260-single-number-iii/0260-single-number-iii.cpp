class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> fre;

        for(auto &num:nums){
            fre[num]++;
        }

        for(auto it=fre.begin(); it!=fre.end(); it++){
            if(it->second == 1){
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};