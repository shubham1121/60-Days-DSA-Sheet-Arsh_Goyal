//With extra space set

class Solution {
public:
    
  void generateAllSubsets(int start,int end,vector<vector<int>>&res,vector<int>&currSub,vector<int>&nums,set<vector<int>>&uset)
    { if(uset.find(currSub)==uset.end()){res.push_back(currSub); uset.insert(currSub);}
      for(int i=start;i<=end;i++)
      { currSub.push_back(nums[i]);
        generateAllSubsets(i+1,end,res,currSub,nums,uset);
        currSub.pop_back();
      }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>checkDuplicates;
        vector<vector<int>>res;
        vector<int>currSub;
        generateAllSubsets(0,nums.size()-1,res,currSub,nums,checkDuplicates);
        return res;
    }
};

// Without extra space
class Solution {
public:
    
  void generateAllSubsets(int start,int end,vector<vector<int>>&res,vector<int>&currSub,vector<int>&nums)
    { res.push_back(currSub);
      for(int i=start;i<=end;i++)
      { if(i>start && nums[i]==nums[i-1]) continue;
          currSub.push_back(nums[i]);
        generateAllSubsets(i+1,end,res,currSub,nums);
        currSub.pop_back();
      }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>currSub;
        generateAllSubsets(0,nums.size()-1,res,currSub,nums);
        return res;
    }
};