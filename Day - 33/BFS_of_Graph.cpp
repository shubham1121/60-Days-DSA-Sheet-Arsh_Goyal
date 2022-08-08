// T.C -: O(V+E ) & S.C -: O(V)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        bool visited[V+1]; // just to ensure not to visite same vertex again
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }
        queue<int>q;
        q.push(0);
        visited[0]=true;
        ans.push_back(0);
        while(!q.empty())
        { int u = q.front();
          q.pop();
          for( int v : adj[u])
          {
              if(!visited[v])
              { ans.push_back(v);
                visited[v]=true;
                q.push(v);
              }
          }
        }
        return ans;
    }
};