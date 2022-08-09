// T.C -: O(V+E) & S.C -: O(V)
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int>adj[],int src,bool vis[],bool recSt[])
    {  vis[src]=true;
       recSt[src]=true;
          for(int v: adj[src])
          {
              if(!vis[v] && dfs(adj,v,vis,recSt))
                 return true;
              else if(recSt[v])
                  return true;
          }
          recSt[src]=false;
      return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        bool vis[V+1];
        bool recSt[V+1]; // recursive call stack to get the back edge
        for(int i=0;i<V;i++)
        {vis[i]=recSt[i]=false;}
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,i,vis,recSt))
                return true;
            }
        }
        return false;
    }
};