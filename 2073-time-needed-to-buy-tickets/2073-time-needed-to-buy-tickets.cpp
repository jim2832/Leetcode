class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        while(tickets[k]){
            for(int i=0; i<tickets.size(); i++){
                if(!tickets[k]){
                    break;
                }
                if(tickets[i]){
                    tickets[i]--;
                    time++;
                }
            }
        }

        return time;
    }
};