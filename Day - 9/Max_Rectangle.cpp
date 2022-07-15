// T.C -: O(N*(M+N)) S.C -: O(N+M)
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
  int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int left[n],right[n];
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left[i]=0;
            }
            else
            {
                left[i]=s.top()+1;
            }
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && heights[s.top()]>=heights[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                right[i]=n-1;
            }
            else
            {
                right[i]=s.top()-1;
            }
            s.push(i);
        }
        
        int maxAns=0;
        for(int i=0;i<n;i++)
        {
            maxAns = max(maxAns,heights[i]*(right[i]-left[i] + 1));
        }
        return maxAns;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int>v(m,0);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                {
                    v[j]+=1;
                }
                else
                {
                    v[j]=0;
                }
            }
            ans = max(ans,largestRectangleArea(v));
        }
        return ans;
    }
};

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
