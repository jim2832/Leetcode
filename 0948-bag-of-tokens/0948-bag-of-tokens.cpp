class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int score = 0;
        int i=0, j=tokens.size()-1;

        while(i <= j){
            if(i == j && power < tokens[i]){
                break;
            }
            if(power < tokens[i] && score == 0){
                break;
            }
            if(power >= tokens[i]){
                power -= tokens[i];
                score++;
                i++;
            }
            else{
                power += tokens[j];
                score--;
                j--;
            }
        }

        return score;
    }
};