class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int i = 0, j = piles.size()-1;
        int Alice = 0, Bob = 0;
        bool Alice_turn = true;

        while(i <= j){
            if(Alice_turn){
                if(piles[i] > piles[j]){
                    Alice += piles[i];
                    i++;
                }
                else{
                    Alice += piles[j];
                    j--;
                }
            }
            // Bob will get the minimum score to let Alice win
            else{
                if(piles[i] > piles[j]){
                    Bob += piles[j];
                    j--;
                }
                else{
                    Bob += piles[i];
                    i++;
                }
            }
            Alice_turn = !Alice_turn;
        }

        return Alice > Bob;
    }
};