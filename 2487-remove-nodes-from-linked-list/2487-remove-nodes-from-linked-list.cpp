class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode* current = head;
        ListNode* prev = head;
        int cur_max = -INT_MAX;
        
        while(current){
            cur_max = max(cur_max, current->val);
            if(current->val < cur_max){
                prev->next = current->next;
                current = prev->next;
            }
            else{
                prev = current;
                current = current->next;
            }
        }

        return reverse(head);
    }
};

/*

5 2 13 3 8
8 3 13 2 5

*/