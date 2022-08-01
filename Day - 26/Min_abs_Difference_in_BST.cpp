// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    void getMinSub(TreeNode *root,int &prev, int &ans)
    {
        if(root==NULL) return;
        getMinSub(root->left,prev,ans);
        ans = min(ans,abs(prev-root->val));
        prev = root->val;
        getMinSub(root->right,prev,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        int prev = INT_MAX;
        getMinSub(root,prev,ans);
        return ans;
    }
};