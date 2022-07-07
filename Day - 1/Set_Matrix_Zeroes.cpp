//T.C -: O(m*n) 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>vp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    vp.push_back({i,j});
                }
            }
        }
        for(auto x:vp)
        {
            int k = 0;
                    while(k<matrix[x.first].size())
                    {matrix[x.first][k++]=0;}
                    k=0;
                    while(k<matrix.size())
                    {matrix[k++][x.second]=0;}
        }
    }
};