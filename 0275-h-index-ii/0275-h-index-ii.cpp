class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lower = 0;
        int upper = n-1;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            if(citations[mid] >= n - mid){
                upper = mid - 1;
            }
            else{
                lower = mid + 1;
            }
        }

        return n - lower;
    }
};