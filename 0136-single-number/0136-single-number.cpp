class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> record;
        
        // record the frequency of every number
        for(const int &num:nums){
            record[num]++;
        }

        // find the the number whose frequency is 1
        for(auto r:record){
            if(r.second == 1){
                return r.first;
            }
        }

        return -1;
    }
};