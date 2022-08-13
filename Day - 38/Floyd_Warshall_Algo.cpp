// T.C -: O(N*N*N)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	   int n = matrix.size();
	    for(int k=0; k<n; k++){
	        for(int u=0; u<n; u++){
	            for(int v=0; v<n; v++){
	                if(matrix[u][k] != -1 && matrix[k][v] != -1){
	                    if(matrix[u][v] == -1){
	                        matrix[u][v] = matrix[u][k] + matrix[k][v];
	                    }
	                    else{
	                        matrix[u][v] = min(matrix[u][v], matrix[u][k]+matrix[k][v]);
	                    }
	                }
	            }
	        }
	    }
	}
};