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
    stack<ListNode*> Stack;
    void reorderList(ListNode* head) {
        ListNode* current = head;
            int len = 0;

            while(current != nullptr){
                Stack.push(current);
                current = current->next;
                len++;
            }

            current = head;
            // A->B
            // A->C->B C:last_node A:current B:current->next
            for(int i=0; i<len/2; i++){
                ListNode* last_node = Stack.top(); //取出最後一個元素
                Stack.pop();
                last_node->next = current->next;
                current->next = last_node;
                current = current->next->next; //原本在A要變成B
            }
            current->next = nullptr;
    }
};