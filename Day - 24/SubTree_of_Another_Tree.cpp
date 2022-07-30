// T.C -: O(N) & S.C -: O(H)
class Solution {
public:
    
    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root==NULL || subRoot==NULL)
        {
            return root==NULL && subRoot==NULL;
        }
        if(root->val==subRoot->val)
        {
            return isSameTree(root->left,subRoot->left) && isSameTree(root->right,subRoot->right);
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(isSameTree(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};