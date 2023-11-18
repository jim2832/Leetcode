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
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;

        while(current->next){
            int GCD = gcd(current->val, current->next->val);
            ListNode* temp_node = current->next;
            ListNode* new_node = new ListNode(GCD);
            current->next = new_node;
            new_node->next = temp_node;
            current = temp_node;
        }

        return head;
    }
};