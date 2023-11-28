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
    vector<double> averageOfLevels(TreeNode* root) {
        //BFS
        vector<double> result;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            double avg = 0;
            int count = 0;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                avg += current->val;
                count++;
            }
            result.push_back((double)avg/count);
        }

        return result;
    }
};