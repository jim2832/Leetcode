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
    ListNode* reverse(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;
        ListNode* nextNode = nullptr;

        while (currNode) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        // Update the head to point to the new head (prevNode)
        head = prevNode;

        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *front = head;
        ListNode *back = head;
        while(n--){
            back = back->next;
        }

        if(!back)
            return head->next;

        while(back->next){
            front = front->next;
            back = back->next;
        }

        front->next = front->next->next;

        return head;
    }
};