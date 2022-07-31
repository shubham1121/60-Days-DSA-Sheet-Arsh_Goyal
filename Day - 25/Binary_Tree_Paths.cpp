// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    
    void treePaths(TreeNode *root,vector<string>&v,string t)
    { if(root==NULL)
      { 
        return;
      }
      if(root->left==NULL && root->right==NULL)
      {  
                t = t + to_string(root->val);
          v.push_back(t);
      }
      t = t + to_string(root->val) + "->";
      treePaths(root->left,v,t);
      treePaths(root->right,v,t);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        treePaths(root,v,"");
        return v;
    }
};