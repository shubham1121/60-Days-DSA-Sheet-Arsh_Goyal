// Recursive solution
class Solution{   
public:
     bool findSubsetSum(vector<int>&a,int n,int sum)
     { if(sum==0) return true;
       if(i==0) return false;
       
       if(a[i-1]<=sum)
       {
           return findSubsetSum(a,i-1,sum) || findSubsetSum(a,i-1,sum-a[i-1]);
       }
       return findSubsetSum(a,i-1,sum);
     }
    bool isSubsetSum(vector<int>arr, int sum){
        return findSubsetSum(arr,arr.size(),sum);
    }
};

// D.P solution
class Solution{   
public:
     bool findSubsetSum(vector<int>&a,int n,int sum)
     { bool dp[n+1][sum+1];
       for(int i=0;i<=n;i++)
       {dp[i][0]=1;}
       for(int i=1;i<=sum;i++)
       {dp[0][i]=0;}
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=sum;j++)
           {
               if(a[i-1]<=sum)
               {
                   dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][sum];
     }
    bool isSubsetSum(vector<int>arr, int sum){
        return findSubsetSum(arr,arr.size(),sum);
    }
};