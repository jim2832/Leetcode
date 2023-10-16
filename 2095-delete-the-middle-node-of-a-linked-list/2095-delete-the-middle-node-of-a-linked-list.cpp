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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        

        ListNode* current = head;

        // count the lengh of the linked list
        int len = 0;
        while(current->next){
            len++;
            current = current->next;
        }
        len++;
        if(len == 1){
            return nullptr;
        }
        int mid = floor(len/2);

        int count = 0;
        current = head;
        while(count++ != mid-1){
            current = current->next;
        }

        current->next = current->next->next;

        return head;
    }
};