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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int max_width = 0;
        queue<pair<TreeNode*, int>> q; // <node, index>
        q.push({root, 0});

        // level order traversal
        while(!q.empty()){
            int n = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;
            max_width = max(max_width, end_index - start_index + 1); // update the maximal width

            // traverse the nodes below
            for(int i=0; i<n; i++){
                auto current_pair = q.front();
                q.pop();
                auto current_node = current_pair.first;
                int node_index = current_pair.second - start_index;

                if(current_node->left){
                    q.push({current_node->left, 2LL * node_index + 1});
                }

                if(current_node->right){
                    q.push({current_node->right, 2LL * node_index + 2});
                }
            }
        }

        return max_width;
    }
};