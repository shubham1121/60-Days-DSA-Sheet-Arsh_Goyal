// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    int maxi = INT_MIN;
    int maxSum(TreeNode* root)
    { if(root==NULL) return 0;
      int ls = max(0,maxSum(root->left)); //do not consider -ve left sum path
      int rs = max(0,maxSum(root->right)); // do not consider -ve right sum path
      maxi =  max(maxi,root->val+ls+rs);
     return root->val + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        maxSum(root);
        return maxi;
    }
};