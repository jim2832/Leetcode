/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    string s;
    int index = 0;

    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        index = 0;
        int num = 0;
        
        // 解析根節點數值
        while (index < s.size() && isdigit(s[index])) {
            num = num * 10 + (s[index++] - '0');
        }
        
        TreeNode* root = new TreeNode(num);
        helper(root, 1);
        return root;
    }

    void helper(TreeNode* parent, int dep) {
        while (index < s.size()) {
            int cur_depth = 0;
            
            // 計算當前深度
            while (index < s.size() && s[index] == '-') {
                cur_depth++;
                index++;
            }
            
            if (cur_depth != dep) {  // 深度不符，回溯
                index -= cur_depth;  // 回溯 `-`
                return;
            }
            
            int num = 0;
            while (index < s.size() && isdigit(s[index])) {
                num = num * 10 + (s[index++] - '0');
            }

            TreeNode* node = new TreeNode(num);
            if (!parent->left) parent->left = node;
            else parent->right = node;

            helper(node, dep + 1);
        }
    }
};
