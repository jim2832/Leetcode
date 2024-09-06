class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> counting(60, 0);
        int count = 0;

        for(auto &t : time) t %= 60;

        for(auto &t : time){
            count += counting[(60 - t) % 60];
            counting[t]++;
        }

        return count;
    }
};