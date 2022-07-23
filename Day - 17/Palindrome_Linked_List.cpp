// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    
    ListNode *reverseLinkedList(ListNode *head)
    { ListNode *nextHead=NULL;
      while(head!=NULL)
      {
          ListNode *nextNode = head->next;
          head->next=nextHead;
          nextHead=head;
          head=nextNode;
      }
        return nextHead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseLinkedList(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        { if(head->val!=slow->val)
            return false;
           head=head->next;
         slow=slow->next;
        }
        return true;
    }
};