// Union Find algo question Connected Components Question
class UnionFind{
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
 public : 
    int count;
    UnionFind(vector<vector<int>>&stones)
    {
        for(vector<int>&stone : stones)
        { int row = -(stone[0]+1);
          int col = (stone[1]+1);
          parent[row]=row;
          parent[col]=col;
        }
        count=parent.size();
    }
    int find(int x)
    {
        if(parent[x]!=x) parent[x]=find(parent[x]);
        return parent[x];
    }
    void union_(int x, int y)
    { int xset = find(x);
      int yset = find(y);
      if(xset==yset) return;
      count--;
     if(rank[xset]<rank[yset]) parent[xset]=yset;
     else if(rank[xset]>rank[yset]) parent[yset]=xset;
     else
     {
         parent[yset]=xset;
         rank[xset]=rank[yset]+1;
     }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones);
        for(vector<int>&stone : stones)
        { int row = -(stone[0]+1);
          int col = (stone[1]+1);
          uf.union_(row,col);
        }
        return stones.size()-uf.count;
    }
};