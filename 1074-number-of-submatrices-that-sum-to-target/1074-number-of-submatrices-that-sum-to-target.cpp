class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        if(row < 1){
            return 0;
        }

        // calculate the prefix sum
        for(int i=0; i<row; i++){
            for(int j=1; j<col; j++){
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
            }
        }

        int count = 0;
        int sum;
        unordered_map<int, int> hash; // record the freqency of the submatrix sum
        for(int c1=0; c1<col; c1++){
            for(int c2=c1; c2<col; c2++){
                hash.clear();
                hash[0] = 1; // 表示空矩陣和為 0
                sum = 0;
                for(int i=0; i<row; i++){
                    // the sum of submarix
                    if(c1 > 0){
                        sum += matrix[i][c2] - matrix[i][c1-1];
                    }
                    else{
                        sum += matrix[i][c2];
                    }

                    // freqency
                    if(hash.find(sum - target) != hash.end()){
                        count += hash[sum - target];
                    }

                    // update the hash table
                    hash[sum]++;
                }
            }
        }

        return count;
    }
};