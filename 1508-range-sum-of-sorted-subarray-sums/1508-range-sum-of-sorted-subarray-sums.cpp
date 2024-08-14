class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;

        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                vec.push_back(sum);
            }
        }

        sort(vec.begin(), vec.end());

        int result = 0;
        int mod = 1e9 + 7;
        for(int i=left-1; i<right; i++){
            result = (result + vec[i]) % mod;
        }

        return result;
    }
};