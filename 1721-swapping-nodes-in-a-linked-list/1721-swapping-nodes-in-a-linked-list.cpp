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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* q = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        p = head;

        for(int i=0; i<k-1; i++){
            p = p->next;
        }
        for(int i=0; i<len-k; i++){
            q = q->next;
        }

        swap(p->val, q->val);

        return head;
    }
};