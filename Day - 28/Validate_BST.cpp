// T.c -: O(N) & S.C -: O(N)
class Solution {
public:
    
    bool validateBST(TreeNode *root, TreeNode* mini,TreeNode* maxi)
    { if(root==NULL) return true;
      if((mini==NULL || root->val > mini->val) && (maxi==NULL || root->val < maxi->val)){
            return validateBST(root->left, mini, root) && validateBST(root->right, root, maxi);
        }
     return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return validateBST(root,NULL,NULL);
    }
};