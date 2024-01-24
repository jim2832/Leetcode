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
    int count = 0;

    void DFS(TreeNode* root, bitset<10> bits){
        if(!root){
            return;
        }

        // flip the bit
        bits[root->val] = ~bits[root->val];

        // leaf
        if(!root->left && !root->right){
            if(bits.count() <= 1){
                count++;
            }
            return;
        }
        
        // recursively traverse
        DFS(root->left, bits);
        DFS(root->right, bits);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        bitset<10> bits = 0;
        DFS(root, bits);
        return count;
    }
};