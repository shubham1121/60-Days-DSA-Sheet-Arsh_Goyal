// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};