// T.C -: O(N) & S.C -: O(1)
bool findDeadEnd(Node *root, int mini,int maxi)
{ if(root==NULL)
  {return false;}
  if(root->left==NULL && root->right==NULL)
  {
      if(mini==maxi)return true;
      return false;
  }
   return findDeadEnd(root->left,mini,root->data-1) || findDeadEnd(root->right,root->data+1,maxi); 
}

bool isDeadEnd(Node *root)
{ 
    return findDeadEnd(root,1,INT_MAX);
}