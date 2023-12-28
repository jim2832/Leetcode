/*

row: 儘量讓愈多1在前面
col: 比較0跟1的數量，如果0的數量>1的數量，則做flip

*/

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        // check row for flipping
        for(int i=0; i<row; i++){
            string origin = "";
            string flipped = "";
            for(int j=0; j<col; j++){
                origin += to_string(grid[i][j]);
                flipped += to_string(!grid[i][j]);
            }
            // cout << origin << " -> " << flipped << endl;

            // the result of origin
            bitset<32> bits(origin);
            int origin_num = static_cast<int>(bits.to_ulong());

            // the result of flipping
            bitset<32> bits2(flipped);
            int flipped_num = static_cast<int>(bits2.to_ulong());

            if(flipped_num > origin_num){
                for(int j=0; j<col; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // check col for flipping
        for(int j=0; j<col; j++){
            int zero = 0, one = 0;
            for(int i=0; i<row; i++){
                grid[i][j] ? one++ : zero++; // record the number of zero and one
            }
            if(zero > one){
                for(int i=0; i<row; i++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }

        // add up the result
        int sum = 0;
        for(int i=0; i<row; i++){
            string str = "";
            for(int j=0; j<col; j++){
                str += to_string(grid[i][j]);
            }
            bitset<32> row_bits(str);
            sum += static_cast<int>(row_bits.to_ulong());
        }

        return sum;
    }
};