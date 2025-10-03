class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;

        while(empty >= numExchange){
            empty -= numExchange - 1;
            numBottles++;
            numExchange++;
        }

        return numBottles;
    }
};