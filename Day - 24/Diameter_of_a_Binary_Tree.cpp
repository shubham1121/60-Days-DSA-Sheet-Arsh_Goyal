// T.C -: O(N) & S.C -: O(1)
class Solution {
public:
    
    int res=0;
    int getHeightDiameter(TreeNode *root)
    {
        if(root==NULL) return 0;
        int lh = getHeightDiameter(root->left);
        int rh = getHeightDiameter(root->right);
        res = max(res,1+lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = getHeightDiameter(root);
        return res-1;
    }
};