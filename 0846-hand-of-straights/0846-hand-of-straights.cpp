class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> hash;
        for(auto &h : hand) hash[h]++;

        while(!hash.empty()){
            int current = hash.begin()->first;
            for(int i=0; i<groupSize; i++){
                if(!hash.count(current + i)) return false;
                if(--hash[current + i] == 0) hash.erase(current + i);
            }
        }

        return true;
    }
};