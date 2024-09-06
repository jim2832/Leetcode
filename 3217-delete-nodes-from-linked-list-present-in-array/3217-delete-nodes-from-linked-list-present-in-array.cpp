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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(auto &num : nums) s.insert(num);
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        while(head){
            if(!s.count(head->val)){
                prev->next = head;
                prev = prev->next;
            }
            head = head->next;
        }

        prev->next = NULL;

        return dummy->next;
    }
};