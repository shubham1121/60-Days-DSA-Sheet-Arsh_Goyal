// T.C -: O(N) & S.C -: O(N)
Node *inpre(Node* root)
{ 
  root=root->left;
  while(root->right) root=root->right;
    return root;
}
Node *insuc(Node* root)
{ 
  root=root->right;
  while(root->left) root=root->left;
    return root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{ if(root==NULL)
  {return;}
  if(root->key==key)
  {
      if(root->left) pre = inpre(root);
      if(root->right) suc = insuc(root);
  }
  else if(root->key<key) //go to right subtree
  { pre = root;
    findPreSuc(root->right,pre,suc,key);
  }
  else // go to left subtree
  { suc = root;
    findPreSuc(root->left,pre,suc,key);
  }

}