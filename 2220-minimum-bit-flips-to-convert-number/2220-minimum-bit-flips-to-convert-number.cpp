class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        bitset<32> s(start), g(goal);

        for(int i=0; i<32; i++){
            if(s[i] != g[i]) count++;
        }

        return count;
    }
};