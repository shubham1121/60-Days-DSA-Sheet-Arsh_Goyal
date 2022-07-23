// T.C -: O(N) & S.C -: O(N) Stack to get the LSB
class Solution {
public:
    
        ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while(head!=NULL)
        {
            ListNode *nextNode = head->next;
            head->next=newHead;
            newHead=head;
            head=nextNode;
        }
        return newHead;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1,s2;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL)
        {
            s1.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        ListNode *dummy = new ListNode();
        ListNode *temp=dummy;
        int carry=0;
        while(!s1.empty() || !s2.empty() || carry )
        { int sum=0;
          if(!s1.empty())
          {
              sum+=s1.top();
              s1.pop();
          }
         if(!s2.empty())
          {
              sum+=s2.top();
              s2.pop();
          }
         sum+=carry;
         carry = sum/10;
         ListNode * newNode = new ListNode(sum%10);
            temp->next=newNode;
         temp=temp->next;
        }
        dummy->next =  reverseList(dummy->next);
        return dummy->next;
    }
};