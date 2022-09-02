class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>>ans;
        //max_heap
        priority_queue<tuple<double,int,int>>pq;
        for(int i=0;i<p.size();i++)
        {
            double dist = sqrt(p[i][0]*p[i][0] + p[i][1]*p[i][1]);
            pq.push({dist,p[i][0],p[i][1]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size()>0)
        { tuple tp = pq.top();
          pq.pop();
          vector<int>temp;
          temp.push_back(get<1>(tp));
          temp.push_back(get<2>(tp));
          ans.push_back(temp);
        }
        return ans;
    }
};