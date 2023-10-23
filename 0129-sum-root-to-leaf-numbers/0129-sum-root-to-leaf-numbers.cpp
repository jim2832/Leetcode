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
    int sum = 0;
    void solver(TreeNode* root, string str){
        // empty tree
        if(root == nullptr){
            return;
        }
        // leaf node
        if(root->left == nullptr && root->right == nullptr){
            str += to_string(root->val);
            sum += stoi(str);
            return;
        }
        str += to_string(root->val);

        solver(root->left, str);
        solver(root->right, str);
    }

    int sumNumbers(TreeNode* root) {
        string str = "";
        solver(root, str);
        return sum;
    }
};