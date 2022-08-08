// T.C -: O(V+E) & S.C -: O(V)
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfsRec(int src,vector<int>adj[],vector<int>&ans,bool visited[])
    { ans.push_back(src);
      visited[src]=true;
      for(int v : adj[src])
      {
          if(!visited[v])
          { 
            dfsRec(v,adj,ans,visited);  
          }
      }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        bool visited[V+1];
        for(int i=0;i<V;i++) {visited[i]=false;}
        dfsRec(0,adj,ans,visited);
        return ans;
    }
};