// T.C -: O(N) & S.C -: O(N) Used indexing for each node 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        { int size = q.size();
          int first,last;
          int mini = q.front().second;
          for(int i=0;i<size;i++)
          { int curr_idx = q.front().second-mini;
            TreeNode *curr = q.front().first;
            q.pop();
           if(i==0) first=curr_idx;
            if(i==size-1) last = curr_idx;
           if(curr->left){q.push({curr->left,(long long)curr_idx*2+1});}
           if(curr->right){q.push({curr->right,(long long)curr_idx*2+2});}
          }
         ans = max(ans,last-first+1);
        }
        return ans;
    }
};