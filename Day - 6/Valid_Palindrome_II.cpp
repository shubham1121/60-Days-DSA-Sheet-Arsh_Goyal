// T.C -: O(N) S.C -: O(1)
class Solution {
public:
    
    bool checkPal(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int n = s.length();
        int count=0;
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            { 
                return checkPal(s,i+1,j)||checkPal(s,i,j-1);
            }
            i++;j--;
        }
        return true;
    }
};