/*

nums = [1,2,2,4]
s = [1,2,4]

*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> hash;

        for(auto &num:nums){
            hash[num]++;
        }

        for(auto [num, freq] : hash){
            if(freq == 2){
                result.push_back(num);
            }
        }

        for(int i=1; i<=nums.size(); i++){
            if(hash[i] == 0){
                result.push_back(i);
            }
        }

        return result;
    }
};

/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        set<int> s;

        for(int &num:nums){
            if(s.count(num)){
                result.push_back(num);
            }
            s.insert(num);
        }

        for(int i=1; i<=nums.size(); i++){
            if(!s.count(i)){
                result.push_back(i);
            }
        }

        return result;
    }
};
*/