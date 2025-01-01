class Solution {
public:
    int maxScore(string s) {
        int score = 0, maxi = 0;

        for(auto &c : s){
            score += (c == '1');
        }

        for(int i=0; i<s.size()-1; i++){
            s[i] == '0' ? score++ : score--;
            maxi = max(maxi, score);
        }

        return maxi;
    }
};