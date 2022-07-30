// T.C -: O(N*N) & S.C -: O(N) Brute force using hashmap
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[i]=0;
        }
        int cnt=0,celeb=-1;
        for(int i=0;i<n;i++)
        { cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(a[i][j]==1)
                    {
                        mp[j]++;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
            if(cnt==n-1)
            {
                celeb=i;
            }
        }
        for(auto x:mp)
        {
            if(x.second==n-1 && celeb==x.first)
            {
                return celeb;
            }
        }
        return -1;
    }
};

// T.C -: O(N) & S.C -: O(N) using stack

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {  int celeb=-1;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int p1 = st.top(); st.pop();
            int p2 = st.top(); st.pop();
            if(a[p1][p2]==1)
            {
                st.push(p2);
            }
            else
            {
                st.push(p1);
            }
        }
        celeb = st.top();
        int cntZero = 0;
        for(int i=0;i<n;i++)
        {
            if(a[celeb][i]==0)
            cntZero++;
        }
        if(cntZero!=n)
        {return -1;}
        int cntOne=0;
        for(int i=0;i<n;i++)
        {
         if(a[i][celeb]==1)
         {cntOne++;}
        }
        if(cntOne!=n-1) return -1;
        return celeb;
    }
};

// T.C -: O(N) & S.C -: O(1)

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        int celeb=0;
        for(int i=1;i<n;i++)
        {
            if(a[celeb][i]==1)
            {
                celeb=i;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i!=celeb && (a[celeb][i]==1 || a[i][celeb]==0))
            {
                return -1;
            }
        }
        return celeb;
    }
};