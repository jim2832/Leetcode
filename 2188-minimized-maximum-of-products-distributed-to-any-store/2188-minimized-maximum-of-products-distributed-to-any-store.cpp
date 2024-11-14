class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lower = 1, upper = 100000;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            int stores = 0;
            for(auto &quantity : quantities){
                stores += (quantity + mid - 1) / mid;
            }
            stores > n ? lower = mid + 1 : upper = mid - 1;
        }

        return lower;
    }
};