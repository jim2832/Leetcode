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

/*

    1
  2   3
4

level order traversal

*/

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if(root == nullptr)
            return result;

        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
                temp.push_back(current->val);
            }
            result.push_back(temp.back());
        }

        return result;
    }
};