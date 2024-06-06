class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> hash;
        for(auto &h : nums) hash[h]++;

        while(!hash.empty()){
            int first_num = hash.begin()->first;
            for(int cur=first_num; cur<first_num + k; cur++){
                if(!hash.count(cur)) return false;
                if(--hash[cur] == 0) hash.erase(cur);
            }
        }

        return true;
    }
};