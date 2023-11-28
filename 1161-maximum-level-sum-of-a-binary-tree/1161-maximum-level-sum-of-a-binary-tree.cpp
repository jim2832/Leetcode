/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        //BFS
        vector<int> sum_vec;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int sum = 0;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                sum += current->val;
            }
            sum_vec.push_back(sum);
        }

        int result, max = -INT_MAX;
        for(int i=0; i<sum_vec.size(); i++){
            if(max < sum_vec[i]){
                max = sum_vec[i];
                result = i;
            }
        }

        return result+1;
    }
};