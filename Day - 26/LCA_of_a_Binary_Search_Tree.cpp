// T.C -: O(N) & S.c -: O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;
        if(root==p || root==q)
        {return root;}
        TreeNode *lca1 = lowestCommonAncestor(root->left,p,q);
        TreeNode *lca2 = lowestCommonAncestor(root->right,p,q);
        if(lca1!=NULL && lca2!=NULL)
        {
            return root;
        }
        if(lca1!=NULL)
        {return lca1;}
        return lca2;
    }
};