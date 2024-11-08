class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> answer;
        int XOR = 0;

        for(auto &num : nums) XOR ^= num;

        for(int i=n-1; i>=0; i--){
            unsigned int inverted = ~XOR & ((1 << maximumBit) - 1);
            answer.push_back(inverted);
            XOR ^= nums[i];
        }

        return answer;
    }
};