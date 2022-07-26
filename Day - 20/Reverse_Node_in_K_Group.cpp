// T.C -: O(N) & S.C -: O(1)
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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode *temp=head,*newHead=NULL,*prv;
        int cnt=1;
        while(temp!=NULL)
        {
            if(cnt%k==0)
            { ListNode *ptr=temp;
              temp=temp->next;
             cnt++;
                ptr->next=NULL;
              if(newHead==NULL)
              {
                  newHead = reverseList(head);
                  head->next=temp;
                  prv=head;
                  head=newHead;
                  newHead=temp;
              }
             else
             {
                 prv->next = reverseList(newHead);
                 newHead->next=temp;
                 prv=newHead;
                 newHead=temp;
                 
             }
            }
            else
            {
                cnt++; temp=temp->next;
            }
            
        }
        return head;
        
    }
};