//T.C - : O(N*M) S.C -: O(N+M)  brute force
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>v(board.size(),vector<int>(board[0].size()));
        int h[]={1,0,-1,0,1,1,-1,-1};
        int ver[]={0,1,0,-1,1,-1,1,-1};
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            { int cnt_live=0;
                if(board[i][j]==0)
                { 
                    for(int k=0;k<8;k++)
                    {
                        int x = i + h[k];
                        int y = j + ver[k];
                        if(x<0 || x>=board.size()||y<0||y>=board[0].size())
                        {
                            continue;
                        }
                        else
                        {
                            if(board[x][y]==1)
                            {cnt_live++;}
                        }
                    }
                    if(cnt_live==3)
                    {
                        v[i][j]=1;
                    }
                    else
                    {
                        v[i][j]=0;
                    }
                }
                else
                {
                    for(int k=0;k<8;k++)
                    {
                        int x = i + h[k];
                        int y = j + ver[k];
                        if(x<0 || x>=board.size()||y<0||y>=board[0].size())
                        {
                            continue;
                        }
                        else
                        {
                            if(board[x][y]==1)
                            {cnt_live++;}
                        }
                    }
                    if(cnt_live<2)
                    {
                        v[i][j]=0;
                    }
                    else if(cnt_live<=3)
                    {
                        v[i][j]=1;
                    }
                    else
                    {
                        v[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            { 
                board[i][j]=v[i][j];
            }
        }
        
    }
};