class Solution
{
    public:
    //Recursive Solution

    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    { if(n<0) return -1;
      if(n==0) return 0;
      int res = max(maximizeTheCuts(n-x,x,y,z),max(maximizeTheCuts(n-y,x,y,z),maximizeTheCuts(n-z,x,y,z)));
      if(res==-1)
      return -1;
      return res+1;
    }
    // DP solution
    int maximizeTheCuts(int n, int x, int y, int z)
    { int dp[n+1];
      dp[0]=0;
      for(int i=1;i<=n;i++)
      { dp[i]=-1;
          if(i-x>=0)
          dp[i] = max(dp[i],dp[i-x]);
          if(i-y>=0)
          dp[i] = max(dp[i],dp[i-y]);
          if(i-z>=0)
          dp[i] = max(dp[i],dp[i-z]);
          
          if(dp[i]!=-1)
          dp[i]++;
      }
      return dp[n]==-1 ? 0 : dp[n];
    }
};