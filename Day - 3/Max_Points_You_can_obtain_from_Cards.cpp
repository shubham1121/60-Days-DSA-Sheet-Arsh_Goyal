//T.C -: O(N) S.C -: O(1) Sliding Window Approach Apporach
class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum=0,t_sum=0,ans=0;
        int n= a.size();
        for(auto x:a)
        {t_sum+=x;}
        if(n==k)
            return t_sum;
        for(int i=0;i<n-k-1;i++)
        {
            sum+=a[i];
        }
        for(int i=n-k-1;i<n;i++)
        {  sum+=a[i];
            ans = max(ans,t_sum-sum);
            sum-=a[i-(n-k-1)];
        }
        return ans;
    }
};