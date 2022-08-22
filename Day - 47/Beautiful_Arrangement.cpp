// Backtracking select a num and swap with all possible numbers and check if the current combination is valid or not
class Solution {
public:
    int cnt=0;
    int countArrangement(int n) {
        vector<int>a(n,0);
        for(int i=0;i<n;i++) a[i]=i+1;
        check(a,0,n);
        return cnt;
    }
    void check(vector<int>&a,int curr,int &n)
    { if(curr==n) cnt++;
        for(int i=curr;i<n;i++)
        { swap(a[i],a[curr]);
          if((a[curr]%(curr+1))==0 || ((curr+1)%a[curr])==0)
            check(a,curr+1,n);
          swap(a[i],a[curr]);
        }
    }
};