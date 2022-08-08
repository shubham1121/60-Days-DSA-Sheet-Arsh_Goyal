// T.C -: O(M*N) & S.C -: O(M*N)
class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j,bool visited[][301],int n,int m)
    { if(i<0 || i>=n || j<0 || j>=m ) return;
      if(grid[i][j]=='0') return;
      if(!visited[i][j] )
      { visited[i][j]=1;
        dfs(grid,i+1,j,visited,n,m);
        dfs(grid,i-1,j,visited,n,m);
        dfs(grid,i,j+1,visited,n,m);
        dfs(grid,i,j-1,visited,n,m);
      }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        bool visited[301][301];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {visited[i][j]=0;}
        }
        for(int i=0;i<n;i++)
        { 
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                { ans++;
                  dfs(grid,i,j,visited,n,m);  
                }
            }
            
            
        }
        return ans;
    }
};