// Backtracking
class Solution{
public:
    bool isPartitionPossible(int start,int end,int a[],int &currSum,int &target)
    { if(currSum>target) return false;
        if(currSum==target) return true;
      for(int i=start;i<end;i++)
      { currSum+=a[i];
         if(isPartitionPossible(i+1,end,a,currSum,target)) return true;
         currSum-=a[i];
      }
      return false;
    }
    int equalPartition(int n, int a[])
    { int sum=0,currSum=0;
      for(int i=0;i<n;i++)
      {sum+=a[i];}
      if(sum%2!=0) return 0;
      sum/=2;
      return isPartitionPossible(0,n-1,a,currSum,sum);
    }
};