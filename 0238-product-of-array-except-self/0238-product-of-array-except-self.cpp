class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> left_product(n);
        vector<int> right_product(n);

        left_product[0] = 1;
        right_product[n-1] = 1;

        for(int i=1; i<n; i++){
            left_product[i] = left_product[i-1] * nums[i-1];
        }
        for(int i=n-2; i>=0; i--){
            right_product[i] = right_product[i+1] * nums[i+1];
        }

        /* test */
        // for(int i=0; i<n; i++){
        //     cout << left_product[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<n; i++){
        //     cout << right_product[i] << " ";
        // }

        for(int i=0; i<n; i++){
            result[i] = left_product[i] * right_product[i];
        }

        return result;
    }
};