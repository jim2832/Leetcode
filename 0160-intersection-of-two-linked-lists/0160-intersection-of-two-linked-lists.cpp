/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // brute force
        // ListNode* temp;
        // while(headA){
        //     temp = headB;
        //     while(temp){
        //         if(headA == temp){
        //             return headA;
        //         }
        //         temp = temp->next;
        //     }
        //     headA = headA->next;
        // }

        // return nullptr;

        // two pointers
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != ptr2){
            // ptr1
            if(ptr1 == nullptr)
                ptr1 = headB;
            else
                ptr1 = ptr1->next;
            
            // ptr2
            if(ptr2 == nullptr)
                ptr2 = headA;
            else
                ptr2 = ptr2->next;
        }

        return ptr1;
    }
};