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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;

        // walk to the node before a
        for(int i=0; i<a-1; i++){
            current = current->next;
        }
        ListNode* temp1 = current;

        // walk to the node after b
        for(int i=0; i<b-a+2; i++){
            current = current->next;
        }
        ListNode* temp2 = current;

        // redirect
        temp1->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = temp2;

        return list1;
    }
};