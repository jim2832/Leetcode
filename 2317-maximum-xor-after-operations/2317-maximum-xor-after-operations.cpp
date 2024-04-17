/*

3 -> 011
2 -> 010
4 -> 100
6 -> 110

*/

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int result = 0;
        for(auto &num : nums) result |= num;
        return result;
    }
};