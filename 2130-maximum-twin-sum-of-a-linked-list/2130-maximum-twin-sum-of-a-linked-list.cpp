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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* next_node = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current; // Move prev and current one step forward
            current = next_node;
        }
        return prev; // 'prev' will point to the new head of the reversed list
    }

    ListNode* reverseSecondHalf(ListNode* head) {
        // Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        if (prev) {
            prev->next = nullptr;
        }

        // Reverse the second half
        ListNode* reversedSecondHalf = reverseLinkedList(slow);

        // Merge the two halves back together
        if (prev) {
            prev->next = reversedSecondHalf;
        } else {
            head = reversedSecondHalf; // Update the head if reversing the first half
        }

        return head;
    }

    int pairSum(ListNode* head) {
        // calculate the length of the linked list
        ListNode* ptr1 = head;
        int len = 0;
        while(ptr1){
            ptr1 = ptr1->next;
            len++;
        }

        // reverse the second half of the linked list
        ListNode* new_head = reverseSecondHalf(head);

        // declare variables
        int maxx = -INT_MAX;
        ptr1 = head;
        ListNode* ptr2 = head;
        
        // move ptr2 to the middle
        for(int i=0; i<len/2; i++){
            ptr2 = ptr2->next;
        }
        
        // compare
        for(int i=0; i<len/2; i++){
            maxx = max(ptr1->val + ptr2->val, maxx);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return maxx;
    }
};