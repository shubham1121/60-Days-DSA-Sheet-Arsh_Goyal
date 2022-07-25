// T.C -: O(N) & S.C -: O(1)
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *es=NULL,*en=NULL;
        Node *os=NULL,*on=NULL;
        Node *curr=head;
        if(curr==NULL)
        {return head;}
        while(curr!=NULL)
        { if(curr->data%2==0)
            { if(es==NULL)
                { es=curr;
                    en=es;
                }
                else
                { en->next=curr;
                  en=en->next;    
                }
            }
           else
           
               { if(os==NULL)
                { os=curr;
                    on=os;
                }
                else
                { on->next=curr;
                  on=on->next;    
                }
            }
           curr=curr->next;
        }
        if(es==NULL || os==NULL)
        {return head;}
        en->next=os;
        on->next=NULL;
        head=es;
        return head;
    }
};