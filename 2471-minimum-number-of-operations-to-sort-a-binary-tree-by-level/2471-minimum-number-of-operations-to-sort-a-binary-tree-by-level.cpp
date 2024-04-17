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
    int minSwaps(vector<int> arr){
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        int count = 0;
        int n = arr.size();

        for(int i=0; i<n; i++){
            mp[temp[i]] = i;
        }

        for(int i=0; i<n; i++){
            while(mp[arr[i]] != i) {
                swap(arr[i], arr[mp[arr[i]]]);
                count++;
            }
        }

        return count;
    }


    int minimumOperations(TreeNode* root) {
        if(!root) return 0;

        int result = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left){
                    q.push(current->left);
                }
                if(current->right){
                    q.push(current->right);
                }
                temp.push_back(current->val);
            }
            result += minSwaps(temp);
        }

        return result;
    }
};