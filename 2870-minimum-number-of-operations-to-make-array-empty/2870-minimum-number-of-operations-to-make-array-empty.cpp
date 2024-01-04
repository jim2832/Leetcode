class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ope = 0;

        for(auto &num:nums){
            hash[num]++;
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            int freq = iter->second;
            if(freq == 1){
                return -1;
            }
            // 3的倍數，可以一次刪除3個
            else if(freq % 3 == 0){
                ope += (freq / 3);
            }
            // 若不是3的倍數，則用一次刪除2個的方式
            else{
                ope += (freq / 3) + 1;
            }
        }

        return ope;
    }
};