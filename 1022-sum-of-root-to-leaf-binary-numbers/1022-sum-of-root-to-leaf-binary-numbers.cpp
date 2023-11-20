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
    vector<string> nums;

    void traverse(TreeNode* root, string path){
        if(!root){
            return;
        }

        path += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr){
            nums.push_back(path);
        }
        traverse(root->left, path);
        traverse(root->right, path);
    }

    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");

        int sum = 0;
        for(auto &c:nums){
           sum += stoi(c, nullptr, 2);
        }

        return sum;
    }
};