/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// convert linked list to vector
// class Solution {
// public:
//     TreeNode* build(vector<int>& nums, int start, int end){
//         if(start >= end){
//             return nullptr;
//         }
//         int mid = start + (end - start) / 2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = build(nums, start, mid);
//         root->right = build(nums, mid+1, end);

//         return root;
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         // convert linked list to vector
//         vector<int> array;
//         ListNode* current = head;
//         while(current){
//             array.push_back(current->val);
//             current = current->next;
//         }

//         return build(array, 0, array.size());
//     }
// };

// another approach
class Solution {
public:
    TreeNode* build(ListNode* start, ListNode* end){
        if(start == end){
            return nullptr;
        }
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(start, slow);
        root->right = build(slow->next, end);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* end = head;
        while(end){
            end = end->next;
        }
        return build(head, end);
    }
};