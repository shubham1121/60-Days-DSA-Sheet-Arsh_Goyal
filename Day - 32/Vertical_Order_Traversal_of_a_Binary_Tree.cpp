// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    map<int,map<int,multiset<int>>>mp; //used multiset bcz we can have multiple same values
    void verticalTrav(TreeNode *root,int x,int y)
    { if(root==NULL) return;
      mp[x][y].insert(root->val);
      verticalTrav(root->left,x-1,y+1);
      verticalTrav(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        verticalTrav(root,0,0);
        for(auto x:mp)
        {   vector<int>temp;
            for(auto y: x.second)
            {
                temp.insert(temp.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};