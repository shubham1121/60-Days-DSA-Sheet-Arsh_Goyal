// T.C -: O(N*N) & S.C -: O(N)
class Solution {
public:
    
    TreeNode * constructTreePrePost(vector<int>& pre, vector<int>& post,int pres,int pree,int posts,int poste)
    { if(pres>pree) return NULL;
      TreeNode *root = new TreeNode(pre[pres]);
      if(pres==pree) return root;
      int idx=posts;
      while(post[idx]!=pre[pres+1])
      idx++;
      int cnt = idx - posts + 1; 
      root->left = constructTreePrePost(pre,post,pres+1,pres+cnt,posts,idx);
      root->right = constructTreePrePost(pre,post,pres+cnt+1,pree,idx+1,poste-1);
     return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int m = postorder.size();
        return constructTreePrePost(preorder,postorder,0,n-1,0,m-1);
    }
};