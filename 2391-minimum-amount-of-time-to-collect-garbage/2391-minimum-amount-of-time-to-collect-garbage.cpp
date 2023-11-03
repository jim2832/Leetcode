class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int time = 0;
        int M_last = 0, P_last = 0, G_last = 0;

        // prefix sum
        for(int i=1; i<travel.size(); i++){
            travel[i] += travel[i-1];
        }

        for(int i=0; i<garbage.size(); i++){
            for(auto &c:garbage[i]){
                time++;
                // record the last index of garbage type 
                switch(c){
                    case 'M':
                        M_last = i;
                        break;
                    case 'P':
                        P_last = i;
                        break;
                    case 'G':
                        G_last = i;
                        break;
                    default:
                        break;
                }
            }
        }

        if(M_last > 0) time += travel[M_last-1];
        if(P_last > 0) time += travel[P_last-1];
        if(G_last > 0) time += travel[G_last-1];

        return time;
    }
};