class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> hash;
        
        for(auto &str:arr){
            hash[str]++;
        }
        
        for(auto &num:arr){
            if(hash[num] < 2){
                k--;
            }
            if(k == 0){
                return num;
            }
        }

        return "";
    }
};