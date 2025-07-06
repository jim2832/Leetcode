class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> hashMap;
        int result = -1;

        for(auto &num : arr){
            hashMap[num]++;
        }

        for(auto &[n, f] : hashMap){
            if(n == f) result = n;
        }

        return result;
    }
};