// T.C -: O(N) S.C -: (1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp = head;
        while(temp->next!=NULL)
        {
            if(temp->val==temp->next->val)
            {
                ListNode *ptr = temp->next;
                temp->next = ptr->next;
                ptr->next=NULL;
                delete(ptr);
            }
            else
            {
                temp=temp->next;
            }
        }
        return head;
    }
};