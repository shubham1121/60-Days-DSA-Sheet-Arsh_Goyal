// T.C -: O(N) & S.C -: O(1) Create a dummy list and attach only distinct element nodes
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        int cnt=0;
        while(temp!=NULL && temp->next!=NULL)
        {  
            if(temp->val!=temp->next->val)
            {
                curr->next=temp;
                curr=temp;
                temp=temp->next;
            }
            else
            { ListNode *ptr=
                while(temp->next!=NULL && temp->val==temp->next->val)
                {
                    temp=temp->next;
                }
             temp=temp->next;
            }
        }
        if(temp==NULL)
        {
            curr->next=NULL;
        }
        else
        {
            curr->next=temp;
            temp->next=NULL;
        }
        return dummy->next;
    }
};