// T.C -: O(1) S.C -: O(1) check 4 equal sides and 2 equal diagonals.
class Solution {
public:
     
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int,int>umap;
        vector<vector<int>>v = {p1,p2,p3,p4};
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            { if(v[i][0]!=v[j][0]||v[i][1]!=v[j][1])
                {int d = ((v[i][0]-v[j][0])*(v[i][0]-v[j][0]))+((v[i][1]-v[j][1])*(v[i][1]-v[j][1]));
                umap[d]++;}
            }
           
        }
        if(umap.size()==2)
        { int cnt=0;
            for(auto x:umap)
            {
                cnt+=x.second;
            }
         return cnt==6;
        }
        return false;
    }
};