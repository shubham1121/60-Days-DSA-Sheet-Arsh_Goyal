// T.C -: O(N) & S.C -: O(H)
class Solution {
public:
    bool isSameTree(TreeNode *root1,TreeNode *root2)
    { if(root1==NULL || root2==NULL)
        {return root1==NULL && root2==NULL;}
      if(root1->val==root2->val)
      {
          return isSameTree(root1->left,root2->right) && isSameTree(root1->right,root2->left);
      }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return isSameTree(root->left,root->right);
    }
};