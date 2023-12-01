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

/*

[1,2,-3,3,1]
 i    j
 0    2
[3,1]

*/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // convert the linked list to
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }

        // find some elements that sum to 0
        int j;
        for(int i=0; i<arr.size(); i++){
            int current_sum = 0;
            for(j=i; j<arr.size(); j++){
                current_sum += arr[j];
                if(current_sum == 0){
                    break;
                }
            }
            if(current_sum == 0){
                cout << i << " " << j << endl;
                arr.erase(arr.begin()+i, arr.begin()+j+1);
                i--;
            }
        }

        if(arr.empty()){
            return nullptr;
        }

        // convert the array to linked list
        ListNode* start = new ListNode(arr[0]);
        ListNode* current = start;
        for(int i=1; i<arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            current->next = temp;
            current = current->next;
        }

        return start;
    }
};