class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0, end = row*col-1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            int value = matrix[mid/col][mid%col];
            if(target > value){
                start = mid + 1;
            }
            else if(target < value){
                end = mid - 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};