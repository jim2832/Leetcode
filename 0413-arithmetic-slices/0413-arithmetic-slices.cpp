class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int diff;

        if(n < 3){
            return 0;
        }


        for(int i=0; i<n-2; i++){
            diff = nums[i+1] - nums[i]; //紀錄兩個元素的差距
            for(int j=i+2; j<n; j++){ //從第三個元素開始找
                if(nums[j] - nums[j-1] == diff){ //符合的三個元素
                    count++;
                }
                else{
                    break;
                }
            }
        }

        return count;
    }
};