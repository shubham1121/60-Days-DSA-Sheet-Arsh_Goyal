// T.C-: O(N*N) & S.C -: O(N)

class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* generateBST(Node *root,int val)
    { if(root==NULL) 
        {
            root = newNode(val);
            return root;
        }
        if(root->data>val)
        {
            root->left = generateBST(root->left,val);
        }
        else if(root->data<val)
        {
            root->right = generateBST(root->right,val);
        }
    }
    Node* post_order(int pre[], int size)
    {
        Node *root = newNode(pre[0]);
        for(int i=0;i<size;i++)
        {
            generateBST(root,pre[i]);
        }
        return root;
    }
};