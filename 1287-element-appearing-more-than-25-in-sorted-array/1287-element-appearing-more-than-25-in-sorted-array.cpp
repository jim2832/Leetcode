class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> hash;

        for(auto &num:arr){
            hash[num]++;
        }
        for(auto &num:arr){
            if(hash[num] > n / 4){
                return num;
            }
        }

        return -1;
    }
};