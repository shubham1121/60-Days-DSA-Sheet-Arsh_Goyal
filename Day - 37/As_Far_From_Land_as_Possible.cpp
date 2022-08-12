//Almost same as GFG Question Distance of nearest cell having 1
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
	  int m = grid[0].size();
	    queue<pair<int,int>>q;
	  vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    { int i = q.front().first;
	      int j = q.front().second;
	      q.pop();
	      if((i-1)>=0 && ans[i][j]+1<ans[i-1][j])
	      { q.push({i-1,j});
	        ans[i-1][j]=ans[i][j]+1;
	      }
	      if((j-1)>=0 && ans[i][j]+1<ans[i][j-1])
	      { q.push({i,j-1});
	        ans[i][j-1]=ans[i][j]+1;
	      }
	      if((i+1)<n && ans[i][j]+1<ans[i+1][j])
	      { q.push({i+1,j});
	        ans[i+1][j]=ans[i][j]+1;
	      }
	      if((j+1)<m && ans[i][j]+1<ans[i][j+1])
	      { q.push({i,j+1});
	        ans[i][j+1]=ans[i][j]+1;
	      }
	    }
        
        int final_ans  = INT_MIN;
        for(auto &row : ans)
        {
            for(auto &val:row)
            {
                final_ans = max(final_ans,val);
            }
        }
        return (final_ans == 0 || final_ans==INT_MAX) ? -1 : final_ans;
    }
};