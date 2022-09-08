class Solution {
public:
    // vector<vector<vector<int>>>dp; //for memoization
//Recursive Solution T.C -: O(2^N)
//     int findMaxSize(vector<string>&strs,int i,int m,int n)
//     {   if(i==strs.size()) return 0;
        
//         int cntZeroes = count(strs[i].begin(),strs[i].end(),'0');
//         int cntOnes = strs[i].size()-cntZeroes;
//         if(m-cntZeroes>=0 && n-cntOnes>=0)
//             return max(1+findMaxSize(strs,i+1,m-cntZeroes,n-cntOnes), findMaxSize(strs,i+1,m,n));
//         return findMaxSize(strs,i+1,m,n);
//     }
    
// Memoization (Top Down Approach)
// int findMaxSize(vector<string>&strs,int i,int m,int n)
// {   if(i==strs.size()) dp[m][n][i]=0;
//     if(dp[m][n][i]!=-1) return dp[m][n][i];
//     int cntZeroes = count(strs[i].begin(),strs[i].end(),'0');
//     int cntOnes = strs[i].size()-cntZeroes;
//     if(m-cntZeroes>=0 && n-cntOnes>=0)
//       return dp[m][n][i] =  max(1+findMaxSize(strs,i+1,m-cntZeroes,n-cntOnes), findMaxSize(strs,i+1,m,n));
//    return  dp[m][n][i] = findMaxSize(strs,i+1,m,n);
// }

// DP solution (Tabulation Bottom Up Approach)
//     int findMaxSize(vector<string>&strs,int i,int m,int n)
//     {   vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1)));
        
//         for(int i = 1;i<=strs.size();i++)
//         {   int cntZeroes = count(strs[i-1].begin(),strs[i-1].end(),'0');
//             int cntOnes = strs[i-1].size()-cntZeroes;
//             for(int j=0;j<=m;j++)
//             {
//                 for(int k=0;k<=n;k++)
//                 {
//                     if(j-cntZeroes>=0 && k-cntOnes>=0)
//                         dp[i][j][k] = max(1+dp[i-1][j-cntZeroes][k-cntOnes],dp[i-1][j][k]);
//                     else
//                         dp[i][j][k] = dp[i-1][j][k];
//                 }
//             }
//         }
//      return dp[strs.size()][m][n];
//     }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp.resize(m+1,vector<vector<int>>(n+1,vector<int>(strs.size()+1,-1))); //(For Memoization)
        return findMaxSize(strs,0,m,n);
    }
};