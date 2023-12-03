/*

[7,2,1]      [7,2,1]
[6,4,2]  ->  [6,4,2]
[6,5,3] sort [6,5,3]
[3,2,1]      [3,2,1]

*/

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        int row = nums.size();
        int col = nums[0].size();

        // sort every row
        for(int i=0; i<row; i++){
            sort(nums[i].begin(), nums[i].end());
        }

        for(int iter=0; iter<col; iter++){
            priority_queue<int> pq;
            for(int i=0; i<row; i++){
                pq.push(nums[i][0]);
                nums[i].erase(nums[i].begin());
            }
            score += pq.top();
        }

        return score;
    }
};