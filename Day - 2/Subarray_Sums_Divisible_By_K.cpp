//T.C -: O(N*N) S.C-:O(N) prefix sum method
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int pfxSum[n];
         pfxSum[0]=nums[0];
        int count=0;
        for(int i=1;i<n;i++)
        {
            pfxSum[i]=nums[i]+pfxSum[i-1];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            { 
              if((pfxSum[j]-pfxSum[i]+nums[i])%k==0)
              {count++;}
            }
        }
        return count;
    }
};
//T.C -: O(N) S.C-:O(N) Special Algo
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int n = nums.size();
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int rem=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            rem = sum%k;
            if(rem<0){rem+=k;}
            
            if(mp.find(rem)!=mp.end())
            {
                count= count + mp[rem];
                mp[rem]++;
            }
            else
            {
                mp[rem]++;
            }
        }
        return count;
    }
};