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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;

        // node number == 2
        if(head->next->next == nullptr){
            return {-1,-1};
        }

        int index = 2;
        ListNode* current = head->next;
        ListNode* prev = head;
        
        while(current->next){
            // local minimal
            if(prev->val > current->val && current->next->val > current->val){
                critical.push_back(index);
            }
            // local maximal
            else if(prev->val < current->val && current->next->val < current->val){
                critical.push_back(index);
            }
            current = current->next;
            prev = prev->next;
            index++;
        }

        // not found critical node or only 1 critical node
        if(critical.empty() || critical.size() == 1){
            return {-1,-1};
        }

        // calculate the min and max distance
        int n = critical.size() - 1;
        int max = critical[n] - critical[0];
        int min = INT_MAX;
        for(int i=0; i<n; i++){
            if(min > critical[i+1] - critical[i]){
                min = critical[i+1] - critical[i];
            }
        }

        return {min, max};
    }
};