// T.C -: O(V+E) & S.C -: O(V)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int>adj[],bool vis[],int parent,int src)
    {  vis[src]=true;
          for(int v: adj[src])
          {
              if(!vis[v])
              { 
                if(dfs(adj,vis,src,v))
                 return true;
              }
              else if(v!=parent)
              {
                  return true;
              }
          }
      return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V+1];
        for(int i=0;i<V;i++)
        {vis[i]=false;}
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,-1,i))
                return true;
            }
        }
        return false;
    }
};