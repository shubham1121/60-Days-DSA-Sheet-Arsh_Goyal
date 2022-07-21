// T.C -: O(N) & S.C -: O(1) general logic of reversing a number no = no*10 + rem
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if(head->next==NULL) return head->val;
        int ans = 0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            ans = ans*2 + temp->val;
            temp=temp->next;
        }
        return ans;
    }
};