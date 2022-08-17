// T.C -: O(N) & S.C -: O(N) If we found a current sum already earlier in the array that means after the 
// prev sum found next subarray contributes to zero sum uptill now.
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {  int ans = 0, sum = 0;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
           sum+=a[i];
           if(sum==0)
           {
               ans = max(ans,i+1);
           }
           else if(mp.find(sum)!=mp.end())
           {
               ans = max(ans,i-mp[sum]);
           }
           else
           {
               mp[sum]=i;
           }
       }
       return ans;
    }
};