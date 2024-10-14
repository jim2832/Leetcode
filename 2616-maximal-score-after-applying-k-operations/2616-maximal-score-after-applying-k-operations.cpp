class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long result = 0;

        for(auto &num : nums) pq.push(num);

        while(k--){
            result += pq.top();
            pq.push((pq.top() + 3 - 1) / 3);
            pq.pop();
        }

        return result;
    }
};