class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int>st;
        int cnt = n - k;
        vector<int>ans(k,0);
        for(auto x:nums)
        { while(!st.empty() && cnt && st.top()>x)
            {st.pop();cnt--;}
          st.push(x);
        }
        while(!st.empty()  && cnt--)
        {st.pop();}
        while(!st.empty())
        {
            ans[--k]=st.top();
            st.pop();
        }
        return ans;
    }
};