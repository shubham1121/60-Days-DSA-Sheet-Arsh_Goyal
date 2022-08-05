// T.C -: O(N) & S.C -: O(N) BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(q.size()>1)
        { Node*curr = q.front();
          q.pop();
         if(curr==NULL)
         {
             q.push(NULL);
             continue;
         }
         curr->next=q.front();
         if(curr->left){q.push(curr->left);}
         if(curr->right){q.push(curr->right);}
        }
        return root;
    }
};

// T.C -: O(N) & S.C -: O(1) BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        Node *curr = root;
        while(curr->left!=NULL)
        {
            Node *temp = curr;
            while(curr!=NULL)
            {
                curr->left->next=curr->right;
                curr->right->next = curr->next==NULL ? NULL  : curr->next->left;
                curr=curr->next;
            }
            curr=temp->left;
        }
        return root;
    }
};
