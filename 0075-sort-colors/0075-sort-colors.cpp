class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hashMap[3] = {};

        for(auto &num : nums){
            hashMap[num]++;
        }

        int i = 0;
        int cur_num = 0;
        while(i < nums.size()){
            for(int j = 0; j < hashMap[cur_num]; j++){
                nums[i] = cur_num;
                i++;
            }
            cur_num++;
        }
    }
};