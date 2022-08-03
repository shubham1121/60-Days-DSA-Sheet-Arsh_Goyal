// T.C -: O(2^N) & S.C -: O(N)
class Solution {
public:
    
    vector<TreeNode*> generateTree(int l,int r)
    { if(l>r) return {NULL};
        vector<TreeNode*>ans;
     for(int root=l;root<=r;root++)
     {
         vector<TreeNode *> left = generateTree(l,root-1);
         vector<TreeNode *> right = generateTree(root+1,r);
         
         for(auto Node_1:left)
         {
             for(auto Node_2:right)
             {
                 TreeNode * newNode = new TreeNode(root);
                 newNode -> left = Node_1;
                 newNode -> right = Node_2;
                 ans.push_back(newNode);
             }
         }
     }
     return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1,n);
    }
};