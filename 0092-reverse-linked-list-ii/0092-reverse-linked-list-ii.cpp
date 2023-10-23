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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left >= right){
            return head;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* current;
        dummy->next = head;

        // move pre pointer to the left of left position
        // move current pointer to the left position
        int count = 0;
        while(count < left-1){
            pre = pre->next;
            count++;
        }

        // Initialize pointers for reversing the range
        current = pre->next;
        ListNode* next_node = nullptr;
        ListNode* tail = current;

        // Reverse the range from left to right
        while(count < right){
            next_node = current->next; //先保留current的下一個節點
            current->next = pre->next;
            pre->next = current;
            current = next_node; //將current往前移一個
            count++;
        }

        // Connect the tail of the reversed range with the rest of the list
        tail->next = current;

        return dummy->next;
    }
};