// T.C -: O(N) &  S.C -: O(1)
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
};