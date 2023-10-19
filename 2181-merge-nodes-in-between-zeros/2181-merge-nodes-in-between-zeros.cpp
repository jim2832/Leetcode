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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p = head;
        ListNode* q = p->next;
        while(q->next){
            if(q->val == 0){
                p->next = q;
                p = q;
            }
            p->val += q->val;
            q = q->next;
        }
        p->next = nullptr;

        return head;
    }
};