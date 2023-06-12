class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //如果只剩head這一筆資料
        while(head != NULL && head->val == val){
            head = head->next;
        }
        if(head == nullptr){
            return nullptr;
        }

        ListNode* current = head;

        while(current->next != nullptr){
            if(current->next->val == val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head;
    }
};