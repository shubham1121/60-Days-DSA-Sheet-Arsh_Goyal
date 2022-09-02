// Backtracking if currSum and target becomes equal we return true and store the current 
//recursive tree path that we have traversed in to the ans.
class Solution {
public:
    
    bool generateSubsets(int start,int end,vector<int>&nums, vector<int>&currCombinations,vector<vector<int>>&subsets,int &currSum,int &target)
    { if(currSum>target)return false;
      if(currSum==target)return true;
        for(int i=start;i<=end;i++)
        {   if(i>start && nums[i-1]==nums[i])continue;
            currSum+=nums[i];
            currCombinations.push_back(nums[i]); 
            if(generateSubsets(i+1,end,nums,currCombinations,subsets,currSum,target))
            {subsets.push_back(currCombinations);}
            currSum-=nums[i];
            currCombinations.pop_back();
        }
     return false;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>subWithSum;
        vector<int>currCombination;
        int currSum=0;
        int n=candidates.size();
        generateSubsets(0,n-1,candidates,currCombination,subWithSum,currSum,target);
        return subWithSum;
    }
};