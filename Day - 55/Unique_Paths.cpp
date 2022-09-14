class Solution {
public:
    // Recursive Solution
    long long int paths(int m, int n, int i, int j)
    { if(i==m-1 && j==n-1)
        { return 1;}
      if(i>=m || j>=n ) return 0 ;
        return paths(m,n,i+1,j) + paths(m,n,i,j+1);
    }

    // Dynamic Programming Solution
    long long int paths(int m, int n, int i, int j)
    { int dp[m][n];
      for(int i=0;i<n;i++)
      {dp[0][i]=1;}
     for(int i=0;i<m;i++)
      {dp[i][0]=1;}
     for(int i=1;i<m;i++)
     {    
         for(int j=1;j<n;j++)
         {
             dp[i][j]=0;
             dp[i][j] = dp[i-1][j] + dp[i][j-1];
         }
     }
     return dp[m-1][n-1];
    }
    
    int uniquePaths(int m, int n) {
        long long int ans = paths(m,n,0,0);
        return ans;   
    }
};