//T.C -: O(N) S.C -: O(1) //Negative Marking Approach
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int>v;
        for(int i=0;i<nums.size();i++)
        { int curr = abs(nums[i]);
           if(nums[curr-1]<0)
           {
               v.push_back(curr);
           }
          nums[curr-1]*=-1;
        }
        return v;
    }
};