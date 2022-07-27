// T.C -: O(N) & S.C -: O(N)
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    { stack<int>st;
      int n = s.length();
      for(int i=0;i<n;i++)
      {
          if(isdigit(s[i]))
          {
              st.push(s[i]-'0');
          }
          else
          { if(s[i]=='*')
             { int x = st.top();
               st.pop();
                 x*=st.top();
                 st.pop();
                 st.push(x);
             }
             else if(s[i]=='+')
             {
                 int x = st.top();
               st.pop();
                 x+=st.top();
                 st.pop();
                 st.push(x);
             }
             else if(s[i]=='-')
             {
                 int x = -1 * (st.top());
               st.pop();
                 x+=st.top();
                 st.pop();
                 st.push(x);
             }
             else
             {
                 int x = st.top();
                 st.pop();
                 int y = st.top();
               st.pop();
                 y = y/x;
                 st.push(y);
             }
          }
      }
      return st.top();
        
    }
};