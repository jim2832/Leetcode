class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int row = nums.size();
        int col = nums[0].size();
        unordered_map<int, int> hash;
        int count = 0;

        for(int i=0; i<row; i++){
            int start = nums[i][0];
            int end = nums[i][1];
            for(int j=start; j<=end; j++){
                hash[j]++;
            }
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(iter->second){
                count++;
            }
        }

        return count;
    }
};