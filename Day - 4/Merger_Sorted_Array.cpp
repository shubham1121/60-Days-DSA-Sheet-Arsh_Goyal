//T.C -: O(M+N) S.C -: O(M+N)
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int x=0,y=0;
        vector<int>v;
        while(x<m&&y<n)
        {
            if(a[x]<b[y])
            {
                v.push_back(a[x++]);
            }
            else if(a[x]==b[y])
            {
                v.push_back(a[x++]);
                v.push_back(b[y++]);
            }
            else
            {
                v.push_back(b[y++]);
            }
        }
        while(x<m){
            v.push_back(a[x++]);
        }
        while(y<n){
            v.push_back(b[y++]);
        }
        for(int i=0;i<m+n;i++)
        {
            a[i]=v[i];
        }
    }
};