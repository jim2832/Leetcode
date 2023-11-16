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
    int max_depth = -INT_MAX;
    int sum = 0;
    
    // calculate the maximum depth
    void deepest(TreeNode* root, int depth){
        if(!root){
            return;
        }
        if(max_depth < depth){
            max_depth = depth;
        }
        deepest(root->left, depth+1);
        deepest(root->right, depth+1);
    }

    // calculate the sum with the deepest leaves
    void deepestLeavesSum(TreeNode* root, int depth){
        if(!root){
            return;
        }
        if(depth == max_depth){
            sum += root->val;
        }
        deepestLeavesSum(root->left, depth+1);
        deepestLeavesSum(root->right, depth+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        deepest(root, 0);
        deepestLeavesSum(root, 0);
        return sum;
    }
};