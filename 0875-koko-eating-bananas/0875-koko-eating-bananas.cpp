class Solution {
public:
    bool CanEatAll(vector<int>& piles, int k, int h){
        int time = 0;
        for(int i=0; i<piles.size(); i++){
            time += (piles[i]-1) / k + 1;
            if(time > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int slow = 1;
        int fast = *max_element(piles.begin(), piles.end());

        while(slow < fast){
            int mid = slow + (fast - slow) / 2; // (slow + fast) / 2
            if(CanEatAll(piles, mid, h)){
                fast = mid;
            }
            else{
                slow = mid + 1;
            }
        }

        return slow;
    }
};