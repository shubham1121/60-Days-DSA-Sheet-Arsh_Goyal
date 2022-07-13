// T.C -: O(N) S.C -: O(N)
class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string temp="";
        for(int i=0;i<s.length();i++)
        { if(s[i]==' ')
            {
                if(temp=="")
                {
                    continue;
                }
               else
               {
                   st.push(temp);
                   temp="";
               }
            }
          else
          {
              temp+=s[i];
          }
        }
        if(temp!="")
        {
            st.push(temp);
        }
        s="";
        while(!st.empty())
        {
            s+=st.top()+" ";
            st.pop();
        }
        s.pop_back();
        return s;
    }
};