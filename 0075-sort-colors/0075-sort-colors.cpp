class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hashMap[3] = {};

        for(auto &num : nums) {
            hashMap[num]++;
        }

        int index = 0;
        for(int color = 0; color < 3; color++) {
            for(int count = 0; count < hashMap[color]; count++) {
                nums[index++] = color;
            }
        }
    }
};
