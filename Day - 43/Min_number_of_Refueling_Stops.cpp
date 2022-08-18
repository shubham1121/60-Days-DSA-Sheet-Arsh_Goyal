class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int i=0,ans=0,curr_dist=startFuel;
        priority_queue<int>pq; // max_heap
        for(ans = 0; curr_dist < target; ans++)
        {   
          while(i<stations.size() &&  stations[i][0]<=curr_dist)
          {
              pq.push(stations[i++][1]);
          }
            if(pq.empty())
            {
                return -1;
            }
            curr_dist+=pq.top();
                pq.pop();
        }
        return ans;
    }
};