class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score = 0;
        vector<int> stones;
        stones.insert(stones.end(), {a, b, c});
        sort(stones.begin(), stones.end());
        
        while(stones[1] && stones[2]){
            stones[1]--;
            stones[2]--;
            score++;
            sort(stones.begin(), stones.end());
        }

        return score;
    }
};