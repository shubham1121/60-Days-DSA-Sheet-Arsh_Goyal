// T.C -: O(NLogN) & S.C -: O(1) Merge Sort 
class Solution {
public:
    
    ListNode* mergeSortedList(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode *head=NULL,*curr,*temp1=list1,*temp2=list2;
        while(temp1 && temp2)
        { if(temp1->val==temp2->val)
            {
              if(!head) 
              {
                    head=temp1;
                    curr=temp1;
                    temp1=temp1->next; 
                }
              else
              {
                  curr->next = temp1;
                  curr=temp1;
                  temp1=temp1->next;
              }
            }
           else if(temp1->val>temp2->val)
           {
               if(!head)
               {head=temp2;curr=temp2;temp2=temp2->next;}
               else
               {curr->next=temp2; curr=temp2;temp2=temp2->next;}
           }
         else
         {
             if(!head)
             {head=temp1;curr=temp1; temp1=temp1->next;}
             else
             {curr->next=temp1;curr=temp1;temp1=temp1->next;}
         }
        }
        if(temp1)
        {curr->next=temp1;}
        if(temp2)
        {curr->next=temp2;}
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *slow=head,*fast=head,*temp=NULL;
        while(fast!=NULL && fast->next!=NULL)
        { temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);
        return mergeSortedList(l1,l2);
    }
    
    
};