// T.C -: O(N) & S.C -: O(N) Similar to binary search but we are processing both parts of mid
class Solution {
public:
    TreeNode* generateBST(vector<int>&a,int st,int end)
    { if(st>end)
        {return NULL;}
     int mid = (st+end)/2;
     TreeNode *root = new TreeNode(a[mid]);
     root->left = generateBST(a,st,mid-1);
     root->right = generateBST(a,mid+1,end);
     return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        return generateBST(nums,0,nums.size()-1);
    }
};