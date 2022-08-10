// T.C -: O(N*N) & S.C -: O(N*N)
class Solution 
{   
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{ int move[8][2]={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
	  bool vis[N+1][N+1];
	  memset(vis,0,sizeof(vis));
	  vis[KnightPos[0]][KnightPos[1]]=1;
	  queue<pair<int,int>>q;
	  q.push({KnightPos[0],KnightPos[1]});
	  int ans=0;
	  while(!q.empty())
	  { int sz = q.size();
	    while(sz--)
	    { pair<int,int>p = q.front();
	      q.pop();
	      int x = p.first,y=p.second;
	      if(x==TargetPos[0] && y == TargetPos[1])
	      {
	          return ans;}
	      for(int k=0;k<8;k++)
	      { int new_x = x + move[k][0];
	        int new_y = y + move[k][1];
	        if(new_x>0 && new_x<=N && new_y>0 && new_y<=N && !vis[new_x][new_y])
	        { vis[new_x][new_y]=1;
	          q.push({new_x,new_y});
	        }
	      }
	      
	    }
	    ans++;
	  }
	  return -1;
	}
};