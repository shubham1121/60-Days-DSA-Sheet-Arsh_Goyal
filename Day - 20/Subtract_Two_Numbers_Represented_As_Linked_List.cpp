// T.C -: O(N+M) & S.C -: O(N)
Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* pre = NULL;
    Node* curr = NULL;
    Node* temp = head;
    while(temp != NULL){
        
        pre = curr;
        curr= temp;
        temp = temp->next;
        curr->next = pre;
    }
    return curr;
    
}
bool check(Node* l1, Node* l2){
    Node* temp1 = l1;
    Node* temp2 = l2;
    while(temp1!=NULL){
        if(temp2->data>temp1->data){
            return false;
        }
        if(temp1->data == temp2->data){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(temp2->data<temp1->data){
            return true;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
    
}
Node* subLinkedList(Node* l1, Node* l2)
{
    // Your code here
    
    while(l1 && l1->data==0){
        Node* temp = l1->next;
        l1 = NULL;
        l1=temp;
    }
    while(l2 && l2->data==0){
        Node* temp = l2->next;
        l2 = NULL;
        l2=temp;
    }
    
    int len1 = 0;
    int len2 = 0;
    Node* c = l1;
    while(c!=NULL){
        len1++;
        c=c->next;
    }
    c=l2;
    while(c!=NULL){
        len2++;
        c=c->next;
    }
    
    if(l2 == NULL){
        return l1;
    }
    if(l1 == NULL){
        l2->data = l2->data;
        return l2;
    }
    
    // cout << len1 << " " << len2 << endl;
   
    
    
    Node* temp = new Node(-1);
    Node* head = temp;
    
    Node* c1=NULL;
    Node* c2=NULL;
    bool flag = true;
    if(len1<len2){
        flag = false;
    }
    else if(len1 == len2){
        flag = check(l1,l2);
    }
    
    l1 = reverse(l1);
    // return l1;
    l2 = reverse(l2);
    
    if(flag){
        c1 = l1;
        c2 = l2;
    }
    else{
        c1 = l2;
        c2 = l1;
    }
   
    int borrow = 0;
    while(c1!= NULL){
        int diff = borrow + c1->data - (c2!=NULL ? c2->data:0);
        if(diff<0){
            borrow=-1;
            diff+=10;
        }
        else{
            borrow =0;
        }
        temp->next = new Node(diff);
        temp=temp->next;
        c1=c1->next;
        if(c2!=NULL){
            c2=c2->next;
        }
    }
    Node* ans = reverse(head->next);
    while(ans != NULL && ans->data==0){
        ans=ans->next;
    }
    if(ans==NULL){
        ans = new Node(0);
    }
    return ans;
    
    
}