class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> hash;
        
        for(int &i:arr){
            hash[i]++;
        }
        
        int max = -1;
        for(auto &pair:hash){
            if(pair.first == pair.second){
                if(max < pair.first){
                    max = pair.first;
                }
            }
        }

        return max;
    }
};