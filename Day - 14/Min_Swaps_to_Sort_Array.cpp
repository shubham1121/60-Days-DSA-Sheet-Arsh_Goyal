// T.C -: O(NLogN) S.C -: O(N) Sorting Hashing
class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{ int cnt=0;
	  vector<int>temp=nums;
	  sort(temp.begin(),temp.end());
	  unordered_map<int,int>mp;
	  for(int i=0;i<nums.size();i++)
	  {
	      mp[nums[i]]=i;
	  }
	  for(int i=0;i<nums.size();i++)
	  {
	      if(nums[i]!=temp[i])
	      {  int ini = nums[i];
	          swap(nums[i],nums[mp[temp[i]]]);
	          mp[ini]=mp[temp[i]];
	          mp[temp[i]]=i;
	          cnt++;
	      }
	  }
	  return cnt;
	}
};