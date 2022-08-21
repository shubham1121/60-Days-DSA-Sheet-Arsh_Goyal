//Generate all subsets from the given array
class Solution {
public:
    
    void generateAllSubsets(int start,int end,vector<vector<int>>&res,vector<int>&currSub,vector<int>&nums)
    { res.push_back(currSub);
      for(int i=start;i<=end;i++)
      { currSub.push_back(nums[i]);
        generateAllSubsets(i+1,end,res,currSub,nums);
        currSub.pop_back();
      }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>currSub;
        generateAllSubsets(0,nums.size()-1,res,currSub,nums);
        return res;
    }
};
