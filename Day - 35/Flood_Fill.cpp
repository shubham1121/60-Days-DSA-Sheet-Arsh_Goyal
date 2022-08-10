// T.C -: O(4^N) & S.C -: O(M*N)
class Solution {
public:
    
    void dfs(vector<vector<int>>&a,int i,int j,int m,int n,int color,int val)
    { if(i<0 || i>=m || j<0 ||j>=n || a[i][j]==color || a[i][j]!=val)
        return ;
          a[i][j]=color;
          dfs(a,i-1,j,m,n,color,val);
          dfs(a,i+1,j,m,n,color,val);
          dfs(a,i,j-1,m,n,color,val);
          dfs(a,i,j+1,m,n,color,val);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        dfs(image,sr,sc,m,n,color,image[sr][sc]);
        return image;
    }
};