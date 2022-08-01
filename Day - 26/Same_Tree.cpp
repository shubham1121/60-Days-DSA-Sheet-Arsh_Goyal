// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL)
        {
            return p==NULL && q==NULL ? true:false;
        }
        if(p->val==q->val)
        {
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};