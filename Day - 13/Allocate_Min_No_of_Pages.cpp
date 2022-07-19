// T.C -: O(NLogN) S.C -: O(1)
class Solution 
{
    public:
    
    bool canAllocate(int a[],int n,int maxi,int m)
    { int pages=0,student=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxi) return false;
            if(a[i]+pages>maxi)
            {
                student++;
                pages=a[i];
            }
            else{
                pages+=a[i];
            }
        }
        return student<=m;
    }
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    { int mini = INT_MAX,sum=0;
      for(int i=0;i<n;i++)
      {
          mini=min(mini,a[i]);
          sum+=a[i];
      }
      int low=mini,high=sum;
      while(low<=high)
      {
          int mid = (high+low)/2;
          if(canAllocate(a,n,mid,m))
          {
              high=mid-1;
          }
          else
          {
              low=mid+1;
          }
      }
        return low;
    }
};