// T.C -: O(N) && S.C -: O(N)
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node *prev=NULL;
    Node * bToDLL(Node *root)
    { if(root==NULL) return root;
      Node* head = bToDLL(root->left);
      if(prev==NULL) //only null when its the left most node
      {head=root;}
      else
      {
          root->left=prev;
          prev->right=root;
      }
      prev=root;
      bToDLL(root->right);
      return head;
    }
};