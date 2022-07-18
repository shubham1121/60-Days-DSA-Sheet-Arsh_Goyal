//T.c -: O(N) && S.C -: O(N) using stack data structure
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                   return false;
                }
            }
            else if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
       return st.empty();
    }
};