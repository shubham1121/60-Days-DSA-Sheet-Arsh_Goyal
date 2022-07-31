// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL||root2==NULL)
        {
            return root1==NULL ? root2:root1;
        }

        //creating new tree
        
        // TreeNode *root = new TreeNode((root1->val+root2->val));
        // root->left = mergeTrees(root1->left,root2->left);
        // root->right = mergeTrees(root1->right,root2->right);

        //modifying existing tree
        root1->val = root1->val + root2->val;
        root1->left = mergeTrees(root1->left,root2->left);
        root1->right = mergeTrees(root1->right,root2->right);
        return root1;
    }
};