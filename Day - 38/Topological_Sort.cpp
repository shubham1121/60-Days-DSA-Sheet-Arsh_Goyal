// T.C -: O(V+E)
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto adjacent : adj[i]){
            inDegree[adjacent]++;
        }
    }
    
    for(int i=0;i<V;i++){
        if(inDegree[i]==0)q.push(i);
    }
    
    vector<int> res;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto adjacent : adj[node]){
            inDegree[adjacent]--;
            if(inDegree[adjacent]==0) q.push(adjacent);
        }
    }
    return res;
	}
};