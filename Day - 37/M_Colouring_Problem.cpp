// T.C -: O(N^M) & S.C -: O(N) Backtracking Trying all possible colors on all nodes 
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int vertex,bool graph[101][101], int n,int col, int color[])
    {
        for(int i=0;i<n;i++)
        {
            if(i!=vertex && graph[i][vertex]==1 && color[i]==col)
            {return false;}
        }
        return true;
    }
    
    bool colorGraph(int vertex,bool graph[101][101], int m,int n, int color[])
    { if(vertex == n) return true;
     
      for(int i = 1;i<=m;i++)
      {
          if(isSafe(vertex,graph,n,i,color))
          { color[vertex] = i;
            if(colorGraph(vertex+1,graph,m,n,color))
            {return true;}
            color[vertex]=0;
          }
      }
     return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n]={0};
        if(colorGraph(0,graph,m,n,color))
        return true;
        
        return false;
    }
};