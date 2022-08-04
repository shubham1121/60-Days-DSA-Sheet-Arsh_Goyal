// T.C -: O(N) & S.C -: O(N)
vector<vector<int>>v;
        if(root==NULL) return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        { int size = q.size();
          vector<int>temp;
          for(int i=0;i<size;i++)
          { TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left) {q.push(node->left);}
            if(node->right) {q.push(node->right);}
          }
          v.push_back(temp);
        }
        return v;