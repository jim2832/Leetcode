class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> result(n);
        queue<int> q;

        sort(deck.begin(), deck.end());

        for(int i=n-1; i>=0; i--){
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            q.push(deck[i]);
        }

        for(int i=n-1; i>=0; i--){
            result[i] = q.front();
            q.pop();
        }

        return result;
    }
};