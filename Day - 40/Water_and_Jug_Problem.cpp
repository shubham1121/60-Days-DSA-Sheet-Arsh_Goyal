// Same really hard to guess graph can be used . BFS solution
class Solution {
public:
    bool canMeasureWater(int m, int n, int d) {
        if((n+m)<d) return false;
	  queue<int>q;
	  q.push(0);
	  unordered_map<int,bool>vis;
	  vis[0]=1;
	  int dir[4]={m,-m,n,-n};
	  while(!q.empty())
	  { int curr = q.front();
	    q.pop();
	   // cout<<curr<<" ";
	    if(curr==d)
	    {return true;}
	    for(int i=0;i<4;i++)
	    { int new_curr = curr + dir[i];
	      if(new_curr<0 || new_curr>(m+n) || vis[new_curr]) continue;
	      else if(new_curr==d) return true;
	      else
	      { vis[new_curr]=1;
	        q.push(new_curr);
	      }
	    }
	  }
	  return false;
    }
};