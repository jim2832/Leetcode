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
        ListNode *front = head;
        ListNode *back = head;
        while(n--){
            back = back->next;
        }

        if(!back)
            return head->next;

        while(back->next){
            front = front->next;
            back = back->next;
        }

        front->next = front->next->next;

        return head;
    }
};