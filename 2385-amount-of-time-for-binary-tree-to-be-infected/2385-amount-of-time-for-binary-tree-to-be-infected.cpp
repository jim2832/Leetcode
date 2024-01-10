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
    unordered_map<int, vector<int>> graph;

    // convert the binary tree into undirected graph
    void convert(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        convert(root->left);
        convert(root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        // convert the binary tree into undirected graph
        convert(root);

        // queue
        queue<int> q;
        q.push(start);

        // reuslt
        int time = 0;

        // nodes which are visited
        unordered_set<int> visited;

        // use BFS to traverse the graph
        while(!q.empty()){
            int size = q.size();
            time++;
            for(int i=0; i<size; i++){
                auto current = q.front();
                q.pop();
                visited.insert(current);
                // traverse the adjacent nodes
                for(auto adj:graph[current]){
                    if(!visited.count(adj)){
                        q.push(adj);
                    }
                }
            }
        }

        return time - 1;
    }
};