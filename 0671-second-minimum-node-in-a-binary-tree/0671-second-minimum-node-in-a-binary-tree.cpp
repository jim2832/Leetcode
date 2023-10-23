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
    void inorder_traverse(TreeNode* root, vector<int>& vec){
        if(root == nullptr){
            return;
        }
        inorder_traverse(root->left, vec);
        vec.push_back(root->val);
        inorder_traverse(root->right, vec);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> result;
        inorder_traverse(root, result);
        sort(result.begin(), result.end());
        auto min = min_element(result.begin(), result.end());
        
        for(int i=0; i<result.size(); i++){
            if(result[i] != *min){
                return result[i];
            }
        }

        return -1;
    }
};