// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    
    int includeRootPathSum(TreeNode *root,long long int sum)
    { if(root==NULL) return 0;
      long long int res=0;
      if(root->val==sum) res++;
      res+=includeRootPathSum(root->left,sum-root->val);
      res+=includeRootPathSum(root->right,sum-root->val);
      return res;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+includeRootPathSum(root,targetSum);
    }
};