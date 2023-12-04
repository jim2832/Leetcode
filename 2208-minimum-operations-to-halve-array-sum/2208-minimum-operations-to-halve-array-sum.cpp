class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        for(auto &num:nums){
            sum += num;
        }

        double half = sum / 2;
        int count = 0;

        priority_queue<double> pq(nums.begin(), nums.end());
        while(sum > half){
            double temp = pq.top();
            pq.pop();
            pq.push(temp / 2);
            sum -= temp / 2;
            count++;
        }

        return count;
    }
};