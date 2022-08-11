// T.C -: O(V+E) & S.C -: O(V) Simply done by using cycle detection in directed graph

class Solution {
public:
    
    bool dfs(vector<vector<int>>&adj,int src,bool vis[],bool recSt[],vector<bool>&present_cycle)
    {  vis[src]=true;
       recSt[src]=true;
        vector<int>list = adj[src];
          for(int v: list)
          {
              if(!vis[v] && dfs(adj,v,vis,recSt,present_cycle))
                 {return present_cycle[src]=true;}
              else if(recSt[v])
                  return present_cycle[src]=true;
          }
          recSt[src]=false;
      return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        bool vis[n+1];
        bool recSt[n+1];
        vector<int>ans;
        vector<bool>present_cycle(n,0);
        for(int i=0;i<n;i++)
        {vis[i]=recSt[i]=false;}
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,vis,recSt,present_cycle);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!present_cycle[i])
            {ans.push_back(i);}
        }
        return ans;
    }
};