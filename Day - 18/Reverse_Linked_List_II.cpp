// T.C -: O(N) & S.C : O(1)
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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || head->next==NULL) return head;
        int cnt=0;
        ListNode *prv = NULL,*end=head,*temp=head;
        while(temp!=NULL) 
        {
            if(cnt==left-1)
            {
                break;
            }
            prv=temp;
            temp=temp->next;
            cnt++;
        }
        while(temp!=NULL)
        {  if(cnt==right-1)
            {
                end=temp->next;
                temp->next=NULL;
                break;
            }
            cnt++;
            temp=temp->next;
        }
        ListNode *newHead = reverseList(prv==NULL ? head: prv->next);
        if(prv==NULL)
        {   head->next=end;
            return newHead;
        }
        prv->next->next=end;
        prv->next=newHead;
        return head;
    }
};