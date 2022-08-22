class Solution {
public:
    vector<vector<int>>permut;
    void recPermut(vector<int>&nums,int start)
    { if(start==nums.size())
        {permut.push_back(nums);}
     unordered_set<int>uset;
     for(int i=start;i<nums.size();i++)
     { if(uset.find(nums[i])!=uset.end()) continue;
       uset.insert(nums[i]);
       swap(nums[i],nums[start]);
       recPermut(nums,start+1);
       swap(nums[i],nums[start]);
     }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        recPermut(nums,0);
        return permut;
    }
};