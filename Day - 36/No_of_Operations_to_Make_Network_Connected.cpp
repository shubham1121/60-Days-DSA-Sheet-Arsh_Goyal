// T.C -: O(V+E) & S.C -: O(V) Normal dfs and logic
class Solution {
public:
    
    void dfs(int src,vector<int>adj[],bool vis[])
    { vis[src]=1;
      for(int &x : adj[src])
      {
          if(!vis[x])
          {
              dfs(x,adj,vis);
          }
      }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        int m  = connections.size();
        if(m < n-1) return -1;
        for(int i=0;i<m;i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        bool vis[n+1];
        for(int i=0;i<n;i++){vis[i]=0;}
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans-1;
    }
};