// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    
    int sumLLeaves(TreeNode* root,bool isLeftChild)
    { if(root==NULL) return 0;
      if(isLeftChild && root->left==NULL && root->right==NULL )
      {return root->val;}
        return sumLLeaves(root->left,true) + sumLLeaves(root->right,false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        return sumLLeaves(root,false);
    }
};