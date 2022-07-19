// T.C -: O(N) S.C -: O(N)
class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
      vector<long long int>v(n,1);
      long long temp=1;
      for(int i=0;i<n;i++)
      {
        v[i]=temp;
        temp*=nums[i];
      }
      temp=1;
      for(int i=n-1;i>=0;i--)
      {
          v[i]*=temp;
          temp*=nums[i];
      }
      return v; 
    }
};