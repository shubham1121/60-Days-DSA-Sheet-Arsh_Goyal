//T.C -: O(N*M*3^K) S.C -: O(a) Graph DFS Backtracking
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int n)
    { if(n==word.size())
        return true;
      if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n] ) return false;
      
     board[i][j]='0';
     bool status = dfs(board,word,i+1,j,n+1)||dfs(board,word,i,j+1,n+1)||
         dfs(board,word,i-1,j,n+1)||dfs(board,word,i,j-1,n+1);
        
         board[i][j]=word[n];
     return status;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return false;
        int rows=board.size();
        int cols = board[0].size();
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<cols;j++)
                {
                    if(board[i][j]==word[0] && dfs(board,word,i,j,0))
                    {return true;}
                }
            }
        return false;
    }
};