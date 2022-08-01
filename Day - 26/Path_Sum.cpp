// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {return false;}
        if(root->left==NULL && root->right==NULL)
        {
            return (targetSum-root->val)==0;
        }
return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};