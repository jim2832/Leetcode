/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> result(m, vector<int>(n, -1));
        
        int row_lower = 0, row_upper = m - 1;
        int col_lower = 0, col_upper = n - 1;

        // 0:up, 1:down, 2:left, 3:right
        // 3(right) -> 1(down) -> 2(left) -> 0(up) -> 3(right) -> ...
        int i = 0, j = 0;
        int direction = 3;

        while(row_upper >= row_lower && col_upper >= col_lower){
            if(head){
                result[i][j] = head->val;
                head = head->next;
            }

            switch (direction){
                //up
                case 0:
                    if(i-1 >= row_lower){ //若往上走還沒超過row的下界
                        i--;
                    }
                    else{
                        direction = 3;
                        col_lower++;
                        j++;
                    }
                    break;

                //down
                case 1:
                    if(i+1 <= row_upper){
                        i++;
                    }
                    else{
                        direction = 2;
                        col_upper--;
                        j--;
                    }
                    break;

                //left
                case 2:
                    if(j-1 >= col_lower){
                        j--;
                    }
                    else{
                        direction = 0;
                        row_upper--;
                        i--;
                    }
                    break;

                //right
                case 3:
                    if(j+1 <= col_upper){
                        j++;
                    }
                    else{
                        direction = 1;
                        row_lower++;
                        i++;
                    }
                    break;
            }
        }
        return result;
    }
};