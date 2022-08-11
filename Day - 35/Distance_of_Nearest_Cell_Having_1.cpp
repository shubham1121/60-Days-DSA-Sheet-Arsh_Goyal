// T.C -: O(N*M) & S.C -: O(N*M) B.F.S without vis array 
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{ int n = grid.size();
	  int m = grid[0].size();
	    queue<pair<int,int>>q;
	  vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j}); //storing all 1's first in to queue 
	                ans[i][j]=0;  //initializing those indexes with value 0 since min dist bet 1 and 1 is 0
	            }
	        }
	    }
	    
	    while(!q.empty())
	    { int i = q.front().first;
	      int j = q.front().second;
	      q.pop();
	      if((i-1)>=0 && ans[i][j]+1<ans[i-1][j]) //checking for its top
	      { q.push({i-1,j});
	        ans[i-1][j]=ans[i][j]+1;
	      }
	      if((j-1)>=0 && ans[i][j]+1<ans[i][j-1]) //checking for left
	      { q.push({i,j-1});
	        ans[i][j-1]=ans[i][j]+1;
	      }
	      if((i+1)<n && ans[i][j]+1<ans[i+1][j]) //checking for down
	      { q.push({i+1,j});
	        ans[i+1][j]=ans[i][j]+1;
	      }
	      if((j+1)<m && ans[i][j]+1<ans[i][j+1]) //checking for right
	      { q.push({i,j+1});
	        ans[i][j+1]=ans[i][j]+1;
	      }
	    }
	    return ans;
	}
};