// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL) return NULL;
        int cnt=0;
        ListNode *back=head,*front=head;
        while(cnt!=n)
        {
            back=back->next;
            cnt++;
        }
        if(back==NULL) return head->next;
        while(back->next!=NULL)
        {
            front=front->next;
            back=back->next;
        }
        ListNode *toDelete = front->next;
        front->next=front->next->next;
        delete(toDelete);
        return head;
    }
};