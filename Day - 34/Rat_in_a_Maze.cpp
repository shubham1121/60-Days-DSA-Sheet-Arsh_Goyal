// T.C -: O(4^N) & S.C -: O(N*N) 
class Solution{
    public:
    
    void dfs(vector<vector<int>>&a,int i,int j,int n,string move,vector<string>&ans,bool vis[][6])
    { if(i==n-1 && j==n-1)
        {   ans.push_back(move);
            return;
        }
        // downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
          vis[i][j] = 1;
          dfs(a,i + 1, j, n, move + 'D',ans, vis);
          vis[i][j] = 0;
        }
    
        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
          vis[i][j] = 1;
         dfs(a,i, j-1, n, move + 'L',ans, vis);
          vis[i][j] = 0;
        }
    
        // right 
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
          vis[i][j] = 1;
         dfs(a,i, j+1, n, move + 'R',ans, vis);
          vis[i][j] = 0;
        }
    
        // upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
          vis[i][j] = 1;
          dfs(a,i - 1, j, n, move + 'U',ans, vis);
          vis[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        bool visited[6][6];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {visited[i][j]=false;}
        }
        if(m[0][0]==1)
        dfs(m,0,0,n,"",ans,visited);
        return ans;
    }
};