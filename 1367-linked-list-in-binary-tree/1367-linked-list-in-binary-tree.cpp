class Solution {
public:
    bool match(TreeNode* root, ListNode* head){
        if(head == nullptr) return true;
        else if(root == nullptr) return false;
        else if(root->val != head->val) return false;
        return match(root->left, head->next) || match(root->right, head->next);
    }

    bool DFS(TreeNode* root, ListNode* head){
        if(root == nullptr) return false;
        if(match(root, head)) return true;
        return DFS(root->left, head) || DFS(root->right, head);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return DFS(root, head);
    }
};