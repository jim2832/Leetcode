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
    unordered_map<int ,int> hash;

    void traverse(TreeNode* root){
        if(!root) return;
        hash[root->val]++;
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;

        // traverse the tree
        traverse(root);

        // find the most frequnet frequency
        int max = -INT_MAX;
        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            max = iter->second > max ? iter->second : max;
        }

        for(auto iter=hash.begin(); iter!=hash.end(); iter++){
            if(iter->second == max){
                result.push_back(iter->first);
            }
        }

        return result;
    }
};