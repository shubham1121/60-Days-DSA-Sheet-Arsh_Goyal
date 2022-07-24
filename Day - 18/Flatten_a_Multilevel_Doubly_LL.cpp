// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr= head,*tail=head;
        stack<Node*>st;
        while(curr!=NULL)
        {
            if(curr->child!=NULL)
            { Node *child = curr->child;
              if(curr->next!=NULL)
              {
                  st.push(curr->next);
                  curr->next->prev=NULL;
              }
                 curr->next=child;
                 child->prev=curr; 
             curr->child=NULL;
            }
                tail=curr;
                curr=curr->next;
        }
        while(st.size()>0)
        {
            curr = st.top();
            st.pop();
            tail->next=curr;
            curr->prev=tail;
            while(curr!=NULL)
            {
                curr=curr->next;
                tail=tail->next;
            }
        }
        return head;
    }
};