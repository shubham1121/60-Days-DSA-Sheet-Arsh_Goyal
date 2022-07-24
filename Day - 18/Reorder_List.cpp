// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode *head)
    { ListNode *newHead = NULL;
      while(head!=NULL)
      { ListNode *temp = head;
          head=head->next;
        temp->next=newHead;
       newHead=temp;
      }
        return newHead;
    }
    
    void reorderList(ListNode* head) {
        if(head==NULL ||head->next==NULL || head->next->next==NULL) return ;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *first = head,*second = slow->next;
        slow->next=NULL;
        second = reverseList(second);
        while(second!=NULL)
        { ListNode *temp1 = first->next;
          first->next=second;
          first=temp1;
          ListNode *temp2=second->next;
          second->next=temp1;
          second = temp2;
        }
        // return head;
    }
};