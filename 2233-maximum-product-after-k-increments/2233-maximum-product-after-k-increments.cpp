/*

[24,5,64,53,26,38] -> [5,24,26,38,53,64]
36 36 37 38 53 64
31+12+11=54

*/

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        while(k--){
            int temp = pq.top();
            pq.pop();
            pq.push(temp+1);
        }

        long long result = 1;
        long long mod = 1000000007;
        while(!pq.empty()){
            result = (result * pq.top()) % mod;
            pq.pop();
        }

        return result % mod;
    }
};