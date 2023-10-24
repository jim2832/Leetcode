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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result, result2;
        queue<TreeNode*> q;

        if(root == nullptr)
            return result;

        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            for(int i=0; i<s; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left != nullptr)
                    q.push(current->left);
                if(current->right != nullptr)
                    q.push(current->right);
                temp.push_back(current->val);
            }
            result.push_back(temp);
        }

        for(int i=result.size()-1; i>=0; i--){
            result2.push_back(result[i]);
        }

        return result2;
    }
};