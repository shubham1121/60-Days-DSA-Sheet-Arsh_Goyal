// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    int sum=0;
    int cntCamera(TreeNode* root)
    { if(root==NULL) return 1;
      int lc = cntCamera(root->left);
      int rc = cntCamera(root->right);
      if(lc==0 || rc==0){sum++;return 2;} // if none of its children are being monitored
      if(lc==1 && rc==1) // if both of its children are being monitored but dont have itself
      {return 0;}
      return 1; // already have camera on either of itself
    }
    int minCameraCover(TreeNode* root) {
        if(cntCamera(root)==0) sum++;
        return sum;
    }
};