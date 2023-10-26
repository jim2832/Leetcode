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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);

        // calculate the length of linked list
        ListNode* current = head;
        int len = 0;
        while(current){
            len++;
            current = current->next;
        }

        int part = len / k; //有幾個part
        int rest = len % k; //剩餘的node
        
        current = head;
        ListNode* prev = nullptr;
        for(int i=0; current && i<k; i++, rest--){
            result[i] = current;
            for(int j=0; j<part + (rest>0); j++){
                prev = current;
                current = current->next;
            }
            prev->next = nullptr;
        }

        return result;
    }
};