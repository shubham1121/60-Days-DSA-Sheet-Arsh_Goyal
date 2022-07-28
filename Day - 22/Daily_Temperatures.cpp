// T.C -: O(N) & S.C -: O(N) Next greater element to right
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>v(n,0);
        stack<pair<int,int>>st;
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty())
            {
                while(!st.empty() && st.top().first<=temperatures[i])
                {
                    st.pop();
                }
               if(!st.empty())
               {
                   v[i] = st.top().second - i;
               }
                else
                {
                    v[i] = 0;
                }
            }
            else
            {
                v[i] = 0;
            }
            st.push({temperatures[i],i});
        }
        return v;
    }
};