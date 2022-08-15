// Application of Topological Sort Idea is to think(lexographically) question as a graph question 
class Solution{
    public:
    
    void dfs(vector<int>graph[],int src,string &ans,vector<bool>&vis)
    { vis[src]=1;
      for(int &neighbour : graph[src])
      {
          if(!vis[neighbour])
          {
              dfs(graph,neighbour,ans,vis);
          }
      }
      char ch = 'a'+src;
      ans = ch + ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int>graph[K];
        for(int i=0;i<N-1;i++)
        { string w1 = dict[i];
          string w2 = dict[i+1];
          for(int j=0;j<min(w1.length(),w2.length());j++)
          {
              if(w1[j]!=w2[j])
              {
                  graph[w1[j]-'a'].push_back(w2[j]-'a');
                  break;
              }
          }
        }
        
        vector<bool>vis(K,0);
        string ans = "";
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,ans,vis);
            }
        }
        return ans;
    }
};