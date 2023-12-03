class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int result = 0;
        priority_queue<int> pq;

        // use the priority queue DS
        for(auto &pile:piles){
            pq.push(pile);
        }

        // operations
        while(k--){
            int temp = pq.top();
            pq.pop();
            pq.push(temp - floor(temp / 2));
        }

        while(!pq.empty()){
            result +=pq.top();
            pq.pop();
        }

        return result;
    }
};