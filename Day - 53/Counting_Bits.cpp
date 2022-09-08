class Solution {
public:
    // T.C -: O(NLogN)
    // int cntSetBits(int n)
    // {
    //     int cnt=0;
    //     while(n)
    //     {
    //         cnt+=n&1; //checks if last bit is set or not
    //         n=n>>1; //right shifts bits of n by 1 postion i.e., n/=(2^1);
    //     }
    //     return cnt;
    // }
    
    // vector<int> countBits(int n) {
    //     vector<int>v(n+1,0);
    //     for(int i=0;i<=n;i++)
    //     {
    //         v[i] = cntSetBits(i);
    //     }
    //     return v;
    // }
    // dp solution used previous values to get new value 
    // Point to notice if a number is even then  set bits in x and x/2 are same and
    // if a number is odd then set bits in x = set bits in x/2 + 1.
    vector<int> countBits(int n) {
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++)
        {   if(i%2==0)
            v[i] = v[i/2];
            else
            v[i] = v[i/2] +1;
        }
        return v;
    }
};