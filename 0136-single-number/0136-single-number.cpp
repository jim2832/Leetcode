class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> record;
        
        // record the frequency of every number
        for(const int &num:nums){
            record[num]++;
        }

        // find the the number whose frequency is 1
        for(auto it=record.begin(); it!=record.end(); it++){
            if(it->second == 1){
                return it->first;
            }
        }

        return 0;
    }
};