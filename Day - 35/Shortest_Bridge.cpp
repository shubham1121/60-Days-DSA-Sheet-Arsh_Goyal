// T.C -: O(M*N) & S.C -: O(M*N) BFS + DFS
class Solution {
public:
    int moves[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& a,int n,int sr,int sc,bool vis[][101],queue<pair<int,int>>&q)
    { if(sr<0 || sr>=n || sc<0 || sc>=n || a[sr][sc]==0) return;
      if(!vis[sr][sc])
      { 
          q.push({sr,sc});
          vis[sr][sc]=1;
        dfs(a,n,sr-1,sc,vis,q);
        dfs(a,n,sr+1,sc,vis,q);
        dfs(a,n,sr,sc-1,vis,q);
        dfs(a,n,sr,sc+1,vis,q);
      }
    }
    
    void bfs(vector<vector<int>>& a,int n,bool vis[][101],queue<pair<int,int>>&q, int &ans)
    { 
        while(!q.empty())
            {     int sz = q.size();
                  for(int i=0;i<sz;i++)
                  {
                      auto p = q.front();
                  q.pop();
                  int sr = p.first;
                  int sc = p.second;
                  for(int i=0;i<4;i++)
                  {
                      int new_sr = sr + moves[i][0];
                      int new_sc = sc + moves[i][1];

                      if(new_sr<0 || new_sr>=n || new_sc<0 || new_sc>=n || vis[new_sr][new_sc])
                      {continue;}
                      else
                      { if(a[new_sr][new_sc]==1)
                        {return;}
                        else
                        {
                            vis[new_sr][new_sc]=1;
                            q.push({new_sr,new_sc});
                        }

                      }
                  }
              }

         ans++;
            
        }
        
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        bool vis[101][101];
        queue<pair<int,int>>q;
        int ans = 0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {vis[i][j]=0;}
        }
        for(int i=0;i<n && !flag;i++)
        {
            for(int j=0;j<n && !flag;j++)
            {if(grid[i][j]==1)
                { 
                dfs(grid,n,i,j,vis,q);
                  flag=true;
                }
            }
        }
        bfs(grid,n,vis,q,ans);
        return ans;
    }
};