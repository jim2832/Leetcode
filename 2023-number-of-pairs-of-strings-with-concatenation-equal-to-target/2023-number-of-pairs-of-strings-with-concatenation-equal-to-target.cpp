class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i].size() + nums[j].size() == target.size()){
                    if(nums[i] + nums[j] == target){
                        cout << nums[i] << " " << nums[j] << endl;
                        count++;
                    }
                    if(nums[j] + nums[i] == target){
                        cout << nums[j] << " " << nums[i] << endl;
                        count++;
                    }
                }
            }
        }

        return count;
    }
};