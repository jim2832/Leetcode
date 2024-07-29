class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waiting_time = 0;
        int chef_time = customers[0][0];

        for(auto &customer : customers){
            if(chef_time < customer[0]) chef_time = customer[0];
            
            if(chef_time <= customer[0]) waiting_time += customer[1];
            else waiting_time += chef_time + customer[1] - customer[0];
            
            chef_time += customer[1];
        }


        return waiting_time / customers.size();
    }
};
