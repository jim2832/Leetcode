class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        int max_prod = 1;
        int min_prod = 1; // track negetive product
        int maxi = INT_MIN;

        for(auto &num : nums){
            if(num < 0){
                swap(max_prod, min_prod);
            }

            max_prod = max(num, max_prod * num);
            min_prod = min(num, min_prod * num);

            maxi = max(maxi, max_prod);
        }

        return maxi;
    }
};