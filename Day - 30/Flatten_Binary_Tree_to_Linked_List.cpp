// T.C -: O(N) & S.C -: O(N) tried reverse post order (right,left,root) & 
//modified root->right to previous element which actually is the root of left subtree
class Solution {
public:
    TreeNode *prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left=NULL;
        prev=root;
    }
};
// T.C -: O(N) & S.C -: O(1) the point is preorder traversal hence if curr left exist we will
//find the rightmost node(bcz since it is preorder rightmost node will be the last node) and connect
//it to the curr->right and so on
class Solution {
public:
    // TreeNode *prev=NULL;
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode *prev = curr->left;
                while(prev->right!=NULL)prev=prev->right;
                prev->right = curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};