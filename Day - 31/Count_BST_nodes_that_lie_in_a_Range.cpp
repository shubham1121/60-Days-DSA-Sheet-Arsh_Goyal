// T.C -: O(N) & S.C -: O(N)
class Solution{
public:
    int getCount(Node *root, int l, int h)
    { if(root==NULL) return 0;
      if(root->data<l)
      {
          return getCount(root->right,l,h);
      }
      else if(root->data>h)
      {
          return getCount(root->left,l,h);
      }
      return 1 + getCount(root->left,l,h)+getCount(root->right,l,h);
    }
};