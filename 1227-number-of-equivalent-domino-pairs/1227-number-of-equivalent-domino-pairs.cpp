class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int count = 0;
        map<pair<int, int>, int> hash;
        
        for(int i = 0; i < n; i++){
            int a = dominoes[i][0], b = dominoes[i][1];
            if(hash.find({a,b}) == hash.end() && hash.find({b,a}) == hash.end()){
                hash[{a,b}]++;
            }
            else if(hash.find({a,b}) != hash.end()){
                count+= hash[{a,b}];
                hash[{a,b}]++;
            }
            else if(hash.find({b,a}) != hash.end()){
                count+= hash[{b,a}];
                hash[{b,a}]++;
            }
        }

        return count;
    }
};