class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int lower = *max_element(weights.begin(), weights.end()), upper = 25 * 1e6;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2; // 現在找到的值

            int count = 0;
            int i = 0;

            while(i < n){
                int cur_sum = 0;
                while(i < n && cur_sum + weights[i] <= mid){
                    cur_sum += weights[i++];
                }
                count++;
            }

            if(count > days){
                lower = mid + 1;
            }
            else{
                upper = mid - 1;
            }
        }

        return lower;
    }
};