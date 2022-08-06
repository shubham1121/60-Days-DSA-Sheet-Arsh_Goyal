// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>zigZagOrder;
        if(root==NULL) return zigZagOrder;
        queue<TreeNode*>q;
        q.push(root);
        bool isReverse = false;
        while(!q.empty())
        { 
          int size = q.size();
            vector<int>temp(size);
          for(int i=0;i<size;i++)
          { TreeNode* curr = q.front();
            q.pop();
           if(isReverse){temp[size-i-1]=curr->val;} //if isReverse true then put curr element to the end of vector
           else
            {temp[i]=(curr->val);}
            if(curr->left) {q.push(curr->left);}
            if(curr->right) {q.push(curr->right);}
          }
          // if(isReverse){reverse(temp.begin(),temp.end());}
            zigZagOrder.push_back(temp);
          isReverse = !isReverse;
        }
        return zigZagOrder;
    }
};