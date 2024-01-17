class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();

        map<int, vector<int>> row_elements; // row : elements
        map<int, vector<int>> col_elements; // col : elements

        // record the elements of rows and columns
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                row_elements[i].push_back(grid[i][j]);
                col_elements[j].push_back(grid[i][j]);
            }
        }

        // for(auto &pair:col_elements){
        //     cout << pair.first << ": ";
        //     for(auto &ele:pair.second){
        //         cout << ele << " ";
        //     }
        //     cout << endl;
        // }

        bool flag;
        for(auto &row_pair:row_elements){
            vector<int> row_ele = row_pair.second;
            for(auto &col_pair:col_elements){
                flag = true;
                vector<int> col_ele = col_pair.second;
                for(int i=0; i<row; i++){
                    if(row_ele[i] != col_ele[i]){
                        flag = false;
                    }
                }
                if(flag){
                    count++;
                }
            }
        }

        return count;
    }
};