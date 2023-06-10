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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);

        return result;
    }

    void postorder(TreeNode *current, vector<int> &path){
        if(current == nullptr){
            return;
        }
        postorder(current->left, path);
        postorder(current->right, path);
        path.push_back(current->val);
    }
};