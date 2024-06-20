class Solution {
public:
    int check(vector<int>& position, int mid){
        int total = 1;
        int cur_dis = position[0];

        for(int i=1; i<position.size(); i++){
            if(position[i] - cur_dis >= mid){
                total++;
                cur_dis = position[i];
            }
        }

        return total;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int n = position.size();
        int lower = 0, upper = 1e9;
        int cur_max = 0;
        
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;

            if(check(position, mid) >= m){
                lower = mid + 1;
                cur_max = max(cur_max, mid);
            }
            else{
                upper = mid - 1;
            }
        }

        return cur_max;
    }
};