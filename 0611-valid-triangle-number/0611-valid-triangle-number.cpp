// 兩邊之和大於大三邊
// a + b > c
// 給定一邊 a 則 a > c - b
// [2,2,3,4] -> [4,3,2,2]

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(),nums.end());
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                if(nums[i] < nums[j] + nums[k]){
                    count += k-j;
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return count;
    }
};