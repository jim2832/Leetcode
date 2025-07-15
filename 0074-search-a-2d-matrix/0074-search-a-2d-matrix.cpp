class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int lower = 0, upper = row * col - 1;

        while(lower <= upper){
            int mid = lower + (upper - lower) / 2;
            int value = matrix[mid/col][mid%col];
            if(value == target){
                return true;
            }
            else if(value < target){
                lower = mid + 1;
            }
            else{
                upper = mid - 1;
            }
        }

        return false;
    }
};