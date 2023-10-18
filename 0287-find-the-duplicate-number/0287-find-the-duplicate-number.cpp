class Solution{
public:
    int findDuplicate(vector<int>& nums) {
        /* hash table solution */
        // unordered_map<int, int> hash;

        // for(int i=0; i<nums.size(); i++){
        //     hash[nums[i]]++;
        // }

        // for(auto &pair:hash){
        //     if(pair.second >= 2){
        //         return pair.first;
        //     }
        // }
        
        // return -1;

        /* set solution */
        unordered_set<int> seen;
        for(int num:nums){
            if(seen.find(num) != seen.end()){
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }
};