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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool even = true;
        while(!q.empty()){
            int n = q.size();
            int prev_val = even ? -INT_MAX : INT_MAX;
            for(int i=0; i<n; i++){
                auto current = q.front();
                q.pop();
                int val = current->val;
                // even level -> odd value & increasing order
                if(even && (val % 2 == 0 || val <= prev_val)){
                    return false;
                }
                // odd level -> even value & decreasing order
                if(!even && (val % 2 == 1 || val >= prev_val)){
                    return false;
                }
                // update the prev_val
                prev_val = val;

                // find the nodes of next level
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            even = !even;
        }

        return true;
    }
};

/*
// level order solution
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        // level order
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> nodes;

        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0; i<n; i++){
                auto current = q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                temp.push_back(current->val);
            }
            nodes.push_back(temp);
        }

        for(int i=0; i<nodes.size(); i++){
            auto current_vec = nodes[i];
            // even level -> odd value & increasing order
            if(i % 2 == 0){
                for(auto &ele : current_vec){
                    if(ele % 2 == 0) return false;
                }
                for(int j=1; j<current_vec.size(); j++){
                    if(current_vec[j] <= current_vec[j-1]) return false;
                }
            }
            // odd level -> even value & decreasing order
            else{
                for(auto &ele : current_vec){
                    if(ele % 2 == 1) return false;
                }
                for(int j=1; j<current_vec.size(); j++){
                    if(current_vec[j] >= current_vec[j-1]) return false;
                }
            }
        }

        return true;
    }
};
*/