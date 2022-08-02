// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    void inorderT(TreeNode *root,vector<int>&v)
    { if(root==NULL)
      {return;}
      inorderT(root->left,v);
      v.push_back(root->val);
      inorderT(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorderT(root,v);
        return v;
    }
};

// T.C -: O(N) & S.C -: O(1) Morris Traversal
class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        TreeNode *curr=root;
        while(curr!=NULL)
        { if(curr->left==NULL)
            {
                v.push_back(curr->val);
                curr=curr->right;
            }
          else
          { TreeNode *prev = curr->left;
            while(prev->right!=NULL && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                v.push_back(curr->val);
                curr=curr->right;
            }
          }
        }
        return v;
    }
};