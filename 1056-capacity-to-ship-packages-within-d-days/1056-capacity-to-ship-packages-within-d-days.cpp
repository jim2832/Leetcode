class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lower = *max_element(weights.begin(), weights.end()), upper = 25 * 1e6;
        while(lower <= upper){
            int mid = lower + (upper - lower) / 2; // 現在找到的值
            int count = 0, i = 0;
            while(i < weights.size()){
                int cur_sum = 0;
                while(i < weights.size() && cur_sum + weights[i] <= mid) cur_sum += weights[i++];
                count++;
            }
            count > days ? lower = mid + 1 : upper = mid - 1;
        }

        return lower;
    }
};