/*

1 3 5 6
3 4 6
1 4 6
2 6
3 4 6
1 4 5 6

*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        map<int, int> hash;
        vector<int> freq;

        for(auto &w : wall){
            // accumulate the number
            for(int i=1; i<w.size(); i++){
                w[i] += w[i-1];
            }
            // record the frequency
            for(int i=0; i<w.size(); i++){
                hash[w[i]]++;
            }
        }

        if(hash.size() == 1) return n;

        for(auto &[a, b] : hash) freq.push_back(b);
        sort(freq.begin(), freq.end(), greater<int>());

        return n - freq[1];
    }
};