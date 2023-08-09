// Divide and conquer version

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int len = nums.size();
        
//         // exception
//         if(len == 1){
//             return nums[0];
//         }
//         if(len == 0){
//             return -2147483648;
//         }

//         //宣告左邊和右邊資料之vector
//         vector<int> left_data(nums.begin(), nums.begin() + (len-1)/2);
//         vector<int> right_data(nums.begin() + (len+1)/2, nums.end());

//         //找出每個範圍中的最大值
//         int max_left = maxSubArray(left_data);
//         int max_right = maxSubArray(right_data);
//         int max_mid = maxCrossArray(nums);

//         //判斷何者三者中哪個為最大的
//         return max(max_mid, max(max_left, max_right)); 
//     }

//     int maxCrossArray(vector<int>& nums) {
//         int len = nums.size();
//         int max_center = nums[(len-1)/2];
//         int index_left = -1, index_right = 1,left_sum = 0,right_sum = 0, max = 0;
//         while((len-1)/2+index_left>=0){
//             left_sum += nums[(len-1)/2+index_left];
//             if(left_sum > max)
//                 max = left_sum;
//             index_left--;
//         }
//         max_center += max;

//         max = 0;
//         while((len-1)/2+index_right<len){
//             right_sum += nums[(len-1)/2+index_right];
//             if(right_sum > max)
//                 max = right_sum;
//             index_right++;
//         }
//         max_center += max;
//         return max_center;
//     }
// };

// DP version
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return nums[0];
        }

        vector<int> DP(len); //用來記錄到目前為止的最大值
        DP[0] = nums[0];
        for(int i=1; i<len; i++){
            // 看加上新值後有沒有變大，如果有則更新，沒有的話就只算自己的就好
            DP[i] = max(DP[i-1] + nums[i], nums[i]);
        }

        int max = *max_element(DP.begin(), DP.end()); //取 vector 內之最大值

        return max;
    }
};