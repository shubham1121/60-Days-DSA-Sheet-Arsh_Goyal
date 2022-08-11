// Kosaraju's Algo
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    unordered_map<int,bool> vis;
	
	//topological sort ---> step 1
	void topo(stack<int>&s,int n,vector<int> adj[])
	{
	    vis[n]=true;
	    for(auto it : adj[n])
	    {
	        if(!vis[it]) topo(s,it,adj);
	    }
	    s.push(n);
	   
	}
	
	// transpose ---> step 2
	
	void transpose(vector<int> adj[] , vector<int> trans[],int V){
	    
	    for(int i =0;i<V;i++)
	    {
	        for(auto it : adj[i])
	        {
	            trans[it].push_back(i);
	        }
	    }
	    
	}
	
	
	//dfs of topo stack ---> step 3
	
	void dfs(int x , vector<int>trans[])
	{
	    vis[x] = true;
	    for(auto it: trans[x])
	    {
	        if(!vis[it]) dfs(it,trans);
	    }
	}
	
	
	///total 3 steps --->  recall
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        for(int i =0;i<V;i++)
        {
            if(!vis[i]) topo(s,i,adj);
        }
        
        vector<int> trans[V];
        transpose(adj,trans,V);
        
        vis.clear();
        int ans=0;
        
        while(!s.empty())
        {
            if(!vis[s.top()])
            {
                ans++;
                dfs(s.top(),trans);
            }
            
            s.pop();
        }
        
        return ans;
        
    }
};