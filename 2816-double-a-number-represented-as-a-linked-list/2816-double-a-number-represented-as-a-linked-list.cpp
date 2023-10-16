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
    ListNode* reverse(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* current = head;
        ListNode* temp = NULL;
        while(current){
            temp = current->next;
            current->next = pre;
            pre = current;
            current = temp;
        }

        return pre;
    }

    ListNode* doubleIt(ListNode* head) {
        if(head == nullptr){
            return NULL;
        }

        ListNode* head_rev = reverse(head);
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;

        while(head_rev || carry){
            int sum = 0;
            if(head_rev){
                sum += (head_rev->val * 2);
                head_rev = head_rev->next;
            }

            sum += carry;

            carry = sum / 10;
            ListNode* curr = new ListNode(sum % 10);
            temp->next = curr;
            temp = temp->next;
        }

        return reverse(dummy->next);
    }
};