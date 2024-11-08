class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> answer;
        int XOR = 0, mask = (1 << maximumBit) - 1;

        for(auto &num : nums) XOR ^= num;

        for(int i=nums.size()-1; i>=0; i--){
            unsigned int inverted = ~XOR & mask;
            answer.push_back(inverted);
            XOR ^= nums[i];
        }

        return answer;
    }
};