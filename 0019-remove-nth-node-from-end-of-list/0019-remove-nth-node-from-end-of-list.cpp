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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *current = head;

        // calculate length
        int len = 0;
        while(current){
            current = current->next;
            len++;
        }
        
        // case of deleting head node
        if(len == n) return head->next;

        // move to the node before deleted node
        current = head;
        for(int i = 0; i < len - n - 1; i++){
            current = current->next;
        }
        
        current->next = current->next->next;

        return head;
    }
};