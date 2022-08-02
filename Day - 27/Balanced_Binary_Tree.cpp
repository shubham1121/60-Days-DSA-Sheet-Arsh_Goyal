// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    int heightBalanced(TreeNode *root)
    { if(root==NULL) return 0;
      int lh = heightBalanced(root->left);
     if(lh==-1)
         return -1;
      int rh = heightBalanced(root->right);
      if(rh==-1)
      {return -1;}
      if(abs(lh-rh)>1)
          return -1;
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return heightBalanced(root) == -1 ? false:true; 
    }
};