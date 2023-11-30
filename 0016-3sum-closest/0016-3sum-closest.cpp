/*

[-1,2,1,-4]
[-4,-1,1,2]

*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0] + nums[1] + nums[2];
        
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j < k){
                int temp = nums[i] + nums[j] + nums[k];
                if(abs(target - temp) < abs(target - sum)){
                    sum = temp;
                }
                if(temp == target){
                    return target;
                }
                else if(temp < target){
                    j++;
                }
                else{ // sum > target
                    k--;
                }
            }
        }

        return sum;
    }
};