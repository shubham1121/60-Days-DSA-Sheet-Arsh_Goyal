class Solution{
  public:
    bool help(int i,int bucketNum,int bucketSum, int reqSum,int k,bool selected[],int n,int a[]) {
        if(bucketNum==k+1) return true;
        if(bucketSum>reqSum) return false;
        if(bucketSum==reqSum)
        {return help(0,bucketNum+1,0,reqSum,k,selected,n,a);}
        if(i>=n) return false;
        if(selected[i]) return help(i+1,bucketNum,bucketSum,reqSum,k,selected,n,a);
        else
        { 
          // Select the current element to curr bucket
          selected[i]=true;
          bucketSum+=a[i];
          bool res1 = help(i+1,bucketNum,bucketSum,reqSum,k,selected,n,a);
          //skip the curr element for the current bucket
          selected[i]=false;
          bucketSum-=a[i];
          bool res2 = help(i+1,bucketNum,bucketSum,reqSum,k,selected,n,a);
          return res1 | res2;
        }
        
     return true;
    }  
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if (k==1) return true;

    //  If total number of partitions are more than n, then division is not possible
    if (n < k) return false;

    // if array sum is not divisible by K then we can't divide array into K partitions
    int sum=0;
    for (int i=0; i < n; i++) sum+=a[i];
    if (sum % k !=0) return false;

    //  the required sum of each subset = sum / K
    int reqSum=sum / k;
    bool selected[n];
    for(int i=0;i<n;i++)
    {selected[i]=false;}
    return help(0,1,0,reqSum,k,selected,n,a);
    }
};