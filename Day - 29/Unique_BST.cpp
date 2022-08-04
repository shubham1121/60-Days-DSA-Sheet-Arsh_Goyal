// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    int dp[21] = {0};
    int catlan(int n)
    { dp[0]=dp[1]=1;
     for(int i=2;i<=n;i++)
     {
         for(int j=0;j<i;j++)
         {
             dp[i]+=dp[j]*dp[i-j-1];
         }
     }
     return dp[n];
    }
    
    int numTrees(int n) {
        if(n<=2)
        {return pow(2,n-1);}
        return catlan(n);
    }
};