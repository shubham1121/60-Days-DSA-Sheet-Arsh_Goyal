// T.C - O(LogN) S.C -: O(1)
class Solution {
public:
    string convertToTitle(int n) {
        string ans ="";
        n=n-1;
        while(n>=0)
        {
            ans+='A'+(n)%26;
            n/=26;
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};