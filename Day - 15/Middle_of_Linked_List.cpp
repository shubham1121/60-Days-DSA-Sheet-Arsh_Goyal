// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return head;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};