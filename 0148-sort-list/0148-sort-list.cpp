/**
 * Definition for singly-linked list.
 * struct ListNode{
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr){}
 *     ListNode(int x) : val(x), next(nullptr){}
 *     ListNode(int x, ListNode *next) : val(x), next(next){}
 * };
 */
class Solution{
public:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* left, ListNode* right){
        if(!left)
            return right;
        if(!right)
            return left;

        ListNode* result = nullptr;

        if(left->val <= right->val){
            result = left;
            result->next = merge(left->next, right);
        }
        else{
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    // Merge sort for the linked list
    ListNode* mergeSort(ListNode* node){
        if(!node || !node->next)
            return node;

        ListNode* mid = getMiddle(node);
        ListNode* midNext = mid->next;
        mid->next = nullptr;

        ListNode* left = mergeSort(node);
        ListNode* right = mergeSort(midNext);

        return merge(left, right);
    }

    // Function to get the middle of the linked list
    ListNode* getMiddle(ListNode* node){
        if(!node)
            return nullptr;

        ListNode* slow = node;
        ListNode* fast = node->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head){
        return mergeSort(head);
    }
};