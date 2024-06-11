class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> result;

        map<int, int> hash;
        for(auto &num : arr1) hash[num]++;

        for(auto &num : arr2){
            while(hash[num]){
                result.push_back(num);
                hash[num]--;
            }
            if(hash[num] == 0) hash.erase(num);
        }

        for(auto &[num, freq] : hash){
            while(hash[num]){
                result.push_back(num);
                hash[num]--;
            }
            if(hash[num] == 0) hash.erase(num);
        }

        return result;
    }
};