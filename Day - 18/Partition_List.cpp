// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *nH1=new ListNode(),*nH2=new ListNode();
        ListNode *temp1=nH1,*temp2=nH2,*temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                temp1->next=temp;
                temp=temp->next;
                temp1=temp1->next;
                temp1->next=NULL;
            }
            else
            {
                temp2->next=temp;
                temp=temp->next;
                temp2=temp2->next;
                temp2->next=NULL;
            }
        }
        temp1->next=nH2->next;
        return nH1->next;
    }
};