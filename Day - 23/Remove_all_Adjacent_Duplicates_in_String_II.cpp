// T.C -: O(N) & S.C -: O(N)
class Solution {
public:
    string removeDuplicates(string &s, int k) {
        if(s.size()<k) return s;
        int cnt=0;
        stack<pair<char,int>>st;
        for(int i=0;i<s.size();i++)
        {   
            if(st.empty() || st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else
            {
                auto p = st.top();
                st.pop();
                p.second++;
                st.push(p);
            }
             if(!st.empty() && st.top().second==k)
            {
                st.pop();
            }
        }
        string ans= "";
        while(!st.empty())
        {   auto p = st.top();
            cnt = p.second;
            while(cnt--)
            {ans +=p.first;}
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};