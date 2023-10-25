class Solution {
public:
    // vector<int> findDuplicates(vector<int>& nums) {
    //     unordered_map<int, int> hash;
    //     vector<int> result;
        
    //     for(int &num:nums){
    //         hash[num]++;
    //     }

    //     for(auto iter=hash.begin(); iter!=hash.end(); iter++){
    //         if(iter->second > 1){
    //             result.push_back(iter->first);
    //         }
    //     }

    //     return result;
    // }

    vector<int> findDuplicates(vector<int>& nums){
        set<int> s;
        vector<int> result;
        
        for(int &num:nums){
            if(s.count(num))
                result.push_back(num);
            else
                s.insert(num);
        }

        return result;
    }
};