//T.C -: O(NLogN) S.C-O(1) Sliding Window Approach
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long ans = INT_MAX;
    sort(a.begin(),a.end());
    int x=m-1,i=0;
        while(x<n && i<n)
        {
            ans = min(ans,a[x]-a[i]);
            i++; x++;
        }
        return ans;
    }   
};