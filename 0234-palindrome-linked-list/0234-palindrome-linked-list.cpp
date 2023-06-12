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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int len = 0;

        if(head == nullptr || head->next == nullptr){
            return true;
        }

        //計算linked list長度
        ListNode *current = head;
        while(current->next != nullptr){
            len++;
            current = current->next;
        }
        len++;

        //將前半段的linked list記錄到stack中
        current = head;
        for(int i=0; i<len/2; i++){
            s.push(current->val);
            current = current->next;
        }
        if(len % 2 == 1){
            current = current->next;
        }
        while(current != nullptr){
            int temp = s.top();
            s.pop();
            if(current->val != temp){
                return false;
            }
            current = current->next;
        }
        return true;
    }
};