/*

[1,0,-1,0,-2,2]
 i j         k

[1,0,-1,0,-2,2] -> [-2,-1,0,0,1,2]

[-2,-1,0,0,1,2]
  i          j

[[-2,-1,1,2],[-2,0,1,1],[-1,0,0,1],[-1,-1,0,2],[-2,0,0,2]]
[[-2,-1,2,1],[-2,0,1,1],[-1,0,1,0],[-1,0,2,-1],[0,0,2,-2]]

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); //sorting

        vector<vector<int>> result;
        set<vector<int>> s;
        int n = nums.size();

        for(int i=0; i<n-2; i++){
            for(int j=n-1; j>=i+2; j--){
                long long new_target = (long long)target - (long long)nums[i] - (long long)nums[j];
                int lower = i+1;
                int upper = j-1;
                while(lower < upper){
                    if(nums[lower] + nums[upper] == new_target){
                        s.insert({nums[i], nums[lower], nums[upper], nums[j]});
                        lower++;
                        upper--;
                    }
                    else if(nums[lower] + nums[upper] < new_target){
                        lower++;
                    }
                    else{
                        upper--;
                    }
                }
            }
        }

        for(auto triplets:s){
            result.push_back(triplets);
        }

        return result;
    }
};