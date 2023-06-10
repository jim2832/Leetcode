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
class Solution{
    public:
        ListNode* swapPairs(ListNode* head){
            //若沒有資料 or 只有一筆
            if(head == nullptr || head->next == nullptr){
                return head;
            }

            ListNode* temp = head->next;
            head->next = swapPairs(temp->next);
            temp->next = head;
            return temp;
        }
};