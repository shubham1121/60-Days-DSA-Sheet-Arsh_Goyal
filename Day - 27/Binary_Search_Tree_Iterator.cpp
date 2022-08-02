// T.C -: O(N) & S.C -: O(N)
class BSTIterator {
private: 
    vector<int>inOrder;
    int index;
    void inorderTraversal(TreeNode *root)
    { if(root==NULL) return;
      inorderTraversal(root->left);
      inOrder.push_back(root->val);
      inorderTraversal(root->right);
    }
public:
    
    BSTIterator(TreeNode* root) {
        inorderTraversal(root);
        index=0;
    }
    
    int next() {
        return inOrder[index++];
    }
    
    bool hasNext() {
        return index<inOrder.size();
    }
};

// T.C -: O(N) & S.C -: O(H)

class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        partialPreOrderTraversal(root);
    }
    
    void partialPreOrderTraversal(TreeNode*root)
    {
        while(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode *top = s.top();
        s.pop();
        partialPreOrderTraversal(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return s.size()!=0;
    }
};