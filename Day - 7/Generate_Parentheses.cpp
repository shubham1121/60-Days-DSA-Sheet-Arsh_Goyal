// T.C -: O(2^(2*N)) S.C -: O(2*N)
class Solution {
public:
    
    void getBalancedParenthesis(int open,int close, vector<string>&v, string op)
    { if(open==0 && close==0)
        {
          v.push_back(op);
            return;
        }
     if(open!=0)
     {
         getBalancedParenthesis(open-1,close,v,op+'(');
     }
     if(open<close)
     {
         getBalancedParenthesis(open,close-1,v,op+')');
     }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        getBalancedParenthesis(n,n,v,"");
        return v;
    }
};