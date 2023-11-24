// [2,4,1,2,7,8] -> [1,2,2,4,7,8]
// [1,2,2,4,7,8]
//  0,1,2,3,4,5

// [9,8,7,6,5,1,2,3,4]
// [1,2,3,4,5,6,7,8,9]

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int times = n / 3;
        int result = 0;
        sort(piles.begin(), piles.end());

        int temp = n-2;
        for(int i=0; i<times; i++){
            result += piles[temp - i*2];
        }

        return result;
    }
};