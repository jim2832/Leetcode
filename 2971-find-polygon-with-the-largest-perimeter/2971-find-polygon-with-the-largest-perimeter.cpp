/*

polygon: 多邊形
perimeter: 周長

多邊形：至少3邊，且最長邊會小於其他邊之和

[1,12,1,2,5,50,3] -> [1,1,2,3,5,12,50]

*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // sorting
        sort(nums.begin(), nums.end());

        int n = nums.size();
        long long perimeter = 0;
        long long prefix_sum = nums[0] + nums[1];

        // traverse the vector
        for(int i=2; i<n; i++){
            if(prefix_sum > nums[i]){
                perimeter = prefix_sum + nums[i];
            }
            prefix_sum += nums[i];
        }

        return perimeter ? perimeter : -1;
    }
};