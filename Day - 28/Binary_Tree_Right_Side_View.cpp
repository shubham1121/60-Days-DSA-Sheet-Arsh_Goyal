// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        // vector<int>v;
        q.push(root);
        while(q.size()!=0)
        { int size = q.size();
          for(int i=0;i<size;i++)
          { TreeNode *curr = q.front();
            q.pop();
            if(i==size-1)
            {
                v.push_back(curr->val);
            }
           if(curr->left) {q.push(curr->left);}
           if(curr->right) {q.push(curr->right);}
          }
        }
        return v;
    }
};