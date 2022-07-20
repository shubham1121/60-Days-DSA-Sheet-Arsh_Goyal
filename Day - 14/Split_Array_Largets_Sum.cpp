// T.C -: O(NLogN) S.C -: O(1)
class Solution {
public:
    
    int checkSubarrayPossible(vector<int>&a,int n,int maxSum)
    { int cntSubArray=1,currSum=a[0];
      for(int i=1;i<n;i++)
      {
          if(currSum+a[i]<=maxSum)
          {
              currSum+=a[i];
          }
          else
          {
              currSum=a[i];
              cntSubArray+=1;
          }
      }
    
     return cntSubArray;  
    }
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(low<=high)
        {
            int mid = (high+low)/2;
            int cnt = checkSubarrayPossible(nums,n,mid);
            if(cnt<=m){ high = mid-1; ans=mid;}
            else
            {
                low = mid+1;
            }
        }
        return low;
    }
};