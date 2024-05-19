/*

任挑一邊 並將兩點都和 k 做 xor，看值有沒有變大

*/

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, count = 0;
        int min_positive = INT_MAX;
        int max_negative = -INT_MAX;
        
        for(auto &vertex_val : nums){
            sum += vertex_val;
            int new_vertex_val = vertex_val ^ k;
            int diff = new_vertex_val - vertex_val;

            if(diff > 0){
                min_positive = min(min_positive, diff);
                sum += diff;
                count++;
            }
            else{
                max_negative = max(max_negative, diff);
            }
        }

        return count % 2 ? max(sum - min_positive, sum + max_negative) : sum;
    }
};