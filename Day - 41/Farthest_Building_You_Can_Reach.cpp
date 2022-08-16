
class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int,vector<int>,greater<int>>min_heap;
        for(int i=1;i<h.size();i++)
        { int diff = h[i]-h[i-1];
          if(diff>0)
          {
              if(min_heap.size()<l)
              {
                  min_heap.push(diff);
              }
              else
              { int br = diff;
                if(min_heap.size()>0 && min_heap.top()<diff)
                {
                    br = min_heap.top();
                    min_heap.pop();
                    min_heap.push(diff);
                }
               if(b-br>=0)
               {
                   b-=br;
               }
               else
               {
                   return i-1;
               }
              }
          }
            
        }
        return h.size()-1;
    }
};