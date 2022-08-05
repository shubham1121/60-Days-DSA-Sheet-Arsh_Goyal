// T.C -: O(N) & S.C -: O(N) Used LCA to find the common link and then calculated dist
//from lca to each of the nodes
class Solution{
    public:
    
    Node* lca(Node*root,int a,int b)
    { if(root==NULL) return NULL;
      if(root->data==a || root->data==b) return root;
      Node *lca1 = lca(root->left,a,b);
      Node *lca2 = lca(root->right,a,b);
      if(lca1 && lca2) return root;
      if(lca1) return lca1;
      return lca2;
    }
    
    static int findDistance(Node *root,int x)
    { if(root==NULL) return 0;
      if(root->data==x) return 1;
      int leftDist = findDistance(root->left,x);
      int rightDist = findDistance(root->right,x);
      if(!leftDist && !rightDist) return 0;
      return leftDist+rightDist+1;
    }
    
    int findDist(Node* root, int a, int b) {
        Node *mylca = lca(root,a,b);
        int alca = findDistance(mylca,a);
        int blca = findDistance(mylca,b);
        return alca+blca-2;
    }
};