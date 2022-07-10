//T.C -: O(N*M) S.C -: O(1) 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int rows = a.size();
        int cols = a[0].size();
        int l = 0, r = cols-1, t = 0, b = rows-1;
        vector<int>res;
        while(l<=r && t<=b)
        {
            for(int i=l;i<=r;i++)
            {
                res.push_back(a[t][i]);
            }
            t++;
            
            for(int i=t;i<=b;i++)
            {
                res.push_back(a[i][r]);
            }
            r--;
            if(t<=b)
            {
                for(int i=r;i>=l;i--)
                {
                    res.push_back(a[b][i]);
                }
                b--;
            }
            if(l<=r)
            {
                for(int i=b;i>=t;i--)
                {
                    res.push_back(a[i][l]);
                }
                l++;
            }
        }
        return res;
    }
};