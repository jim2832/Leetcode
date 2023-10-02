class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> fre; //frequency

        for(auto &num : nums){
            fre[num]++;
        }

        for(auto it=fre.begin(); it!=fre.end(); it++){
            if(it->second == 1){
                return it->first;
            }
        }

        return -1;
    }
};