// T.C -: O(N*N) & S.C -: O(N*N) dfs and flood fill algo 
class Solution{
    bool seen;
    public :
    void mark(vector<vector<char>>& board,int i,int j,int r,int c)
    {
        if(i<0 || i>r-1 || j<0 || j>c-1)
            return;
        if(board[i][j]=='X')
            return;
        
        board[i][j] = 'X';
        mark(board,i-1,j,r,c);
        mark(board,i+1,j,r,c);
        mark(board,i,j-1,r,c);
        mark(board,i,j+1,r,c);       
    }
    void dfs(vector<vector<char>>& board,int i,int j,int r,int c,vector<vector<bool>>& visited)
    {
        if(i<0 || i>r-1 || j<0 || j>c-1)
            return;
        
        if(board[i][j]=='X' || visited[i][j])
            return;
        if(i<=0 || i>=r-1 || j<=0 || j>=c-1)
            seen = true;
        
        visited[i][j] = true;
        dfs(board,i-1,j,r,c,visited);
        dfs(board,i+1,j,r,c,visited);
        dfs(board,i,j-1,r,c,visited);
        dfs(board,i,j+1,r,c,visited);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    { vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(int i=1;i<n-1;++i)
        {
            for(int j=1;j<m-1;++j)
            {
                if(board[i][j]=='O' && !visited[i][j])
                {
                    seen = false;
                    dfs(board,i,j,n,m,visited);
                    if(seen==false)
                        mark(board,i,j,n,m);
                    seen = true;
                }
            }
        }
        return board;
    }
};