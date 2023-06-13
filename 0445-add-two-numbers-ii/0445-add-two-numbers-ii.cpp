/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     long long int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(long long int x) : val(x), next(nullptr) {}
 *     ListNode(long long int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        while(l1)
        {
            num1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            num2.push(l2->val);
            l2=l2->next;
        }
        ListNode* head=NULL;
        int carry=0;
        while(!num1.empty() && !num2.empty())
        {
            int sum=num1.top()+num2.top()+carry;
            num1.pop();
            num2.pop();
            carry=sum/10;
            if(head==NULL)
            {
                head=new ListNode(sum%10);
            }
            else
            {
                ListNode* temp=new ListNode(sum%10);
                temp->next=head;
                head=temp;
            }
        }
        while(!num1.empty())
        {
            int sum=num1.top()+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            num1.pop();
            temp->next=head;
            head=temp;
        }
        while(!num2.empty())
        {
            int sum=num2.top()+carry;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            num2.pop();
            temp->next=head;
            head=temp;
        }
        if(carry)
        {
            ListNode* temp= new ListNode(carry);
            temp->next=head;
            head=temp;
        }
        return head;
        
    }
};