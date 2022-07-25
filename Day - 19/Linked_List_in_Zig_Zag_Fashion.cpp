// T.C -: O(N) & S.C -: O(1)
class Solution
{
    public:
    Node *zigZag(Node* head)
    { if(head->next==NULL) return head;
      Node *temp=head;
      int cnt=0;
      while(temp->next!=NULL)
      { if(cnt%2==0) //Check for greater if cnt even
          {
              if(temp->next->data<temp->data)
              { int val = temp->data;
                temp->data=temp->next->data;
                temp->next->data=val;
              }
          }
          else
          {
              if(temp->next->data>temp->data)
              { int val = temp->data;
                temp->data=temp->next->data;
                temp->next->data=val;
              }
          }
          cnt++;
          temp=temp->next;
      }
      return head;
    }
};