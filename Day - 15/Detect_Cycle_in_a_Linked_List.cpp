// T.C -: O(N) & S.C -: O(1) Floyd's cycle detection algo fast==slow then cycle present
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode *slow=head,*fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return true;
        }
        return false;
    }
};