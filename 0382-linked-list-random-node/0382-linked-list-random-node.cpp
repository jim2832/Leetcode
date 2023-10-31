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
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
        srand(time(0)); // seed the random number generator
    }
    
    int getRandom() {
        int count = 0;
        int result;
        ListNode* current = head;

        while(current){
            count++;
            if(rand() % count == 0){
                result = current->val;
            }
            current = current->next;
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */