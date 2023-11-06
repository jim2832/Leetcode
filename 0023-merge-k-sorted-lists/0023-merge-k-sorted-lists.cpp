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
struct compare {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val; // 從小到大排序
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* current = pq.top(); //走訪每個linked list
            temp->next = current;
            pq.pop();
            temp = temp->next;

            if(current && current->next){
                pq.push(current->next);
            }
        }

        return dummy->next;
    }
};