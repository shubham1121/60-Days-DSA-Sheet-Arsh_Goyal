class Solution {
public:
    int knightDialer(int n) {
        int mod = 1e9 + 7;
        //paths array represents that 0 can be reached from {4,6} and 1 can be reached from {6,8}..
     vector<vector<int>> paths = { {4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};

     vector<vector<int>>dp(n+1,vector<int>(10,0));
      for(int i=0;i<10;i++)
     {dp[1][i]=1;}
     for(int i=2;i<=n;i++)
     {
         for(int j=0;j<10;j++)
         {
             for(auto &x : paths[j])
             {
                 dp[i][j] = (dp[i][j] + dp[i-1][x])%mod;
             }
         }
     }
        int sum =0;
        for(int j=0;j<10;j++)
            {sum = (sum+dp[n][j])%mod;}
        return sum;
    }
};