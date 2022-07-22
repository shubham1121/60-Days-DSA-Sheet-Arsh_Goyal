// T.C -: O(N) & S.C -: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
            if(head==NULL) return head;
            if(head->next==NULL) return head->val==val ? NULL : head;
        ListNode *temp=head,*prv_ptr=head;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                if(temp==head)
                {
                    ListNode* ptr = temp;
                    head=head->next;
                    temp=head;
                    prv_ptr=head;
                    ptr->next=NULL;
                    delete(ptr);
                }
                else
                { prv_ptr->next = temp->next;
                  ListNode *ptr=temp;
                  temp=temp->next;
                  ptr->next=NULL;
                  delete(ptr);
                }
            }
            else
            {
                prv_ptr=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};