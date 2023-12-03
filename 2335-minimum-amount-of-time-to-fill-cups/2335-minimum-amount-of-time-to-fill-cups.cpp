/*
0: [1,4,2]
1: [1,3,1]
2: [0,2,1]
3: [0,1,0]
4: [0,0,0]
*/

/*
priority_queue
[4,2,1] -> [3,1,1] -> [2,1,0] -> [1,0,0] -> [0,0,0]
*/

class Solution {
public:
    int fillCups(vector<int>& amount) {
        // pq
        priority_queue<int> pq(amount.begin(), amount.end());
        int result = 0;

        while(pq.top()){
            int temp1 = pq.top();
            pq.pop();
            int temp2 = pq.top();
            pq.pop();
            if(!temp2){
                temp1--;
                pq.push(temp1);
                pq.push(0);
            }
            else{
                temp1--;
                temp2--;
                pq.push(temp1);
                pq.push(temp2);
            }
            result++;
        }

        return result;
    }
};