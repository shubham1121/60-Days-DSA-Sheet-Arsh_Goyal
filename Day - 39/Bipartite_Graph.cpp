// T.C -: O(V+E) Application of M-Colouring Problem Try to color graph with only two color

class Solution {
    private:
    bool isBipartitehelper(int s,vector<int> & colour,vector<int> adj[])
    {
        queue<int> q;
        colour[s]=0;
        q.push(s);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nbrs:adj[node]){
                if(colour[nbrs]==2)
                {
                    if(colour[node]==0) colour[nbrs]=1;
                    else    colour[nbrs]=0;
                    q.push(nbrs);
                }
                else if(colour[nbrs]==colour[node]) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> colour(V,2);
	    for(int i=0;i<V;i++)
	    {
	        if(colour[i]==2){
	        if(isBipartitehelper(i,colour,adj)==false)
	            return false;
	    }
	    }
	    return true;
	}

};