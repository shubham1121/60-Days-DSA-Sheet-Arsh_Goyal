// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    int ans=-1;
    void ksm(TreeNode*root,int k, int &idx)
    { if(root==NULL) return ;
      ksm(root->left,k,idx);
      if(idx==k){ans=root->val; idx++; return;}
     else{idx++;}
      ksm(root->right,k,idx);
    }
    int kthSmallest(TreeNode* root, int k) {
        int idx = 1;
        ksm(root,k,idx);
        return ans;
    }
};