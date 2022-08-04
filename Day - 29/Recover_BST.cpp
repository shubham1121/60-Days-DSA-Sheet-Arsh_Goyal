// T.C -: O(N) & S.C -: O(N)
class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorderTraversal(TreeNode* root) {
        if(root == NULL) return; 
        
        inorderTraversal(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }

        prev = root;
        inorderTraversal(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorderTraversal(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};